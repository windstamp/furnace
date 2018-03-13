// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "fight/fight_util_object.h"
#include "fight/scene.h"
#include "object/object_pool_mgr.h"

#include "fight/scene_mgr.h"

//-----------------------------------------------------------------------------
// 初始化
//-----------------------------------------------------------------------------
bool SceneMgr::Init()
{
	serial_ = 0;
	
	return true;
}

//-----------------------------------------------------------------------------
// 销毁
//-----------------------------------------------------------------------------
void SceneMgr::Destroy()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
	
	std::list<MemEnterSceneInfo*>	enter_scene_info_list_;
	std::map<int32_t, Scene*>		scene_map_;
	
	for (auto iter = enter_scene_info_list_.begin();
		 iter != enter_scene_info_list_.end();
		 ++iter)
	{
		sObjectPoolMgr->object_pool_scene_info.destroy( &(**iter) );
	}
	
	for (auto iter = scene_map_.begin();
		 iter != scene_map_.end();
		 ++iter)
	{
		sObjectPoolMgr->object_pool_scene.destroy(iter->second);
	}
	
	return;
}

//-----------------------------------------------------------------------------
// 注册战斗
//-----------------------------------------------------------------------------
bool SceneMgr::Register(MemEnterSceneInfo* _info)
{
	if (!_info)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _info";
		
		return false;
	}
	
	if (enter_scene_info_list_.size() >= 20)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Too many entries in list <size = " << enter_scene_info_list_.size() << ">";
		
		return false;
	}
	
	_info->serial = gen_serial();
	
	enter_scene_info_list_.push_back(_info);
	
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "creator_id = " << _info->creator_id << ", scene_entry_id = " << _info->scene_entry_id
		<< ", scene_entry_type = " << _info->scene_entry_type;
	
	return true;
}

//-----------------------------------------------------------------------------
// 每帧更新
//-----------------------------------------------------------------------------
void SceneMgr::Update()
{
	UpdateEnterSceneInfo();
	
	UpdateScene();
	
	return;
}

void SceneMgr::UpdateEnterSceneInfo()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "register to enter scene number: " << enter_scene_info_list_.size();
	
	if ( enter_scene_info_list_.empty() )
		return;
	
	MemEnterSceneInfo* info = enter_scene_info_list_.front();
	
	if (!info)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer info";
		
		return;
	}
	
	Scene* scene = sObjectPoolMgr->object_pool_scene.construct();
	if (!scene)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Object pool construct failed for scene";
		
		return;
	}
	
	int64_t id = info->serial;
	int64_t scene_entry_id = info->scene_entry_id;
		
	bool bRet = scene->Init(info);
	if (!bRet)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Scene init failed with id " << id << " and entry id " << scene_entry_id;

		BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Need to free memory for scene";
		sObjectPoolMgr->object_pool_scene.destroy(scene);
					
		return;
	}
	
	scene_map_[id] = scene;
	
	enter_scene_info_list_.pop_front();
	
	return;
}

void SceneMgr::UpdateScene()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "scene number: " << scene_map_.size();
	
	std::map<int32_t, Scene*>::iterator iter;
	std::map<int32_t, Scene*>::iterator iter_begin	= scene_map_.begin();
	std::map<int32_t, Scene*>::iterator iter_end	= scene_map_.end();
	
	for (iter = iter_begin; iter != iter_end; )
	{
		if ( iter->second->is_delete() )
		{
			DestroyScene(iter->second);
			
			scene_map_.erase(iter++);
		}
		else
		{
			iter->second->Update();
			
			++iter;
		}
	}
	
	return;
}


//-----------------------------------------------------------------------------
// 私有方法
//-----------------------------------------------------------------------------

void SceneMgr::DestroyScene(Scene* _scene)
{
	if (!_scene)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _scene";
		
		return;
	}
	
	_scene->Destroy();
	
	sObjectPoolMgr->object_pool_scene.destroy(_scene);
}
