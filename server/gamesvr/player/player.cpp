// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "container/hero_container.h"
#include "fight/fight_helper.h"
#include "fight/fight_util_object.h"
#include "fight/scene_mgr.h"
#include "object/object_pool_mgr.h"
#include "resource/res_mgr.h"

#include "player/player.h"

Player::Player()
{
}

Player::~Player()
{
	Destroy();
}

bool Player::Init(int64_t _id)
{
	id_	= _id;
	
	hero_container_.Init(this);
	
	int64_t hero_type_id_1 = 20001018;
	int64_t hero_type_id_2 = 30001018;
	hero_container_.AddHero(hero_type_id_1, id_);
	hero_container_.AddHero(hero_type_id_2, id_);
	
	return true;
}

void Player::Destroy()
{
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "id: %ld" << id_;
	
	return;
}

void Player::Update()
{
	int64_t stage_id = 10001001;
	
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "Attack stage <" << stage_id << "> by player <" << id_ << ">";
	
	Attack(stage_id);
}

void Player::Attack(int64_t _stage_id)
{
	int64_t scene_entry_id = 10001001;
	
	MemEnterSceneInfo* scene_info = (MemEnterSceneInfo*)sObjectPoolMgr->object_pool_scene_info.construct();
	if (!scene_info)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Object pool construct failed for scene_info";
		
		return;
	}
	
	scene_info->creator_id 			= id_;
	scene_info->scene_entry_id		= scene_entry_id;
	scene_info->scene_entry_type	= ESFS_Stage;
	
	MemFightGroup* attack_fight_group = sObjectPoolMgr->object_pool_mem_fight_group.construct();
	if (!attack_fight_group)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Object pool construct failed for attack_fight_group";
		
		BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Need to free memory for scene_info";
		sObjectPoolMgr->object_pool_scene_info.destroy(scene_info);
		
		return;
	}
	
	if ( !fight_helper::BuildFightGroup(attack_fight_group, this) )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "fight_helper BuildFightGroup failed.";
	}
	else
	{	
		scene_info->fight_group[EC_Attack] = attack_fight_group;
	}
	
	MemFightGroup* defence_fight_group = sObjectPoolMgr->object_pool_mem_fight_group.construct();
	if (!defence_fight_group)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Object pool construct failed for defence_fight_group";
		
		BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Need to free memory for scene_info";
		BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Need to free memory for attack_fight_group";
		sObjectPoolMgr->object_pool_scene_info.destroy(scene_info);
		sObjectPoolMgr->object_pool_mem_fight_group.destroy(attack_fight_group);
		
		return;
	}
	
	const MemSceneEntry* scene_entry = sResMgr->GetSceneEntry(scene_entry_id);
	if (!scene_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Invalid scene entry: " << scene_entry_id;
		
		BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Need to free memory for scene_info";
		BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Need to free memory for attack_fight_group";
		BOOST_LOG_TRIVIAL(info)	 << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Need to free memory for defence_fight_group";
		sObjectPoolMgr->object_pool_scene_info.destroy(scene_info);
		sObjectPoolMgr->object_pool_mem_fight_group.destroy(attack_fight_group);
		sObjectPoolMgr->object_pool_mem_fight_group.destroy(defence_fight_group);
		
		return;
	}
	
	int64_t fight_group_id = scene_entry->hero_group_id;
	
	if ( !fight_helper::BuildFightGroup(defence_fight_group, fight_group_id) )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "fight_helper BuildFightGroup failed.";
	}
	else
	{	
		scene_info->fight_group[EC_Defence] = defence_fight_group;
	}
		
	
	scene_info->misc_info.stage.pvp					= false;
	scene_info->misc_info.stage.stage_id			= _stage_id;
	scene_info->misc_info.stage.attack_player_id	= id_;
	
	sSceneMgr->Register(scene_info);
	
	return;
}

void Player::OnAttackFinish(MemEnterSceneInfo* _scene_info)
{
	if (!_scene_info)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _scene_info";
		
		return;
	}
	
	if (id_ != _scene_info->creator_id)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "From wrong creator: self_id = " << id_ << " creator_id = " << _scene_info->creator_id;
		
		return;
	}
	
	sObjectPoolMgr->object_pool_scene_info.destroy(_scene_info);
	
	return;
}
