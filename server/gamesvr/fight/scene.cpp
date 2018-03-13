// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "define/fight_define.h"

#include "fight/fightable.h"
#include "fight/fight_group.h"
#include "fight/fight_hero.h"
#include "object/object_pool_mgr.h"
#include "player/player_mgr.h"
#include "resource/res_mgr.h"

#include "fight/scene.h"

//-----------------------------------------------------------------------------
// 构造函数和析构函数
//-----------------------------------------------------------------------------
Scene::Scene()
{
}

Scene::~Scene()
{
}

//-----------------------------------------------------------------------------
// 初始化和销毁
//-----------------------------------------------------------------------------
bool Scene::Init(MemEnterSceneInfo* _info)
{
	if (!_info)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _info";
			
		Destroy();
		
		return false;
	}
	
	id_					= _info->serial;
	creator_id_			= _info->creator_id;
	scene_entry_id_		= _info->scene_entry_id;
	scene_entry_type_	= _info->scene_entry_type;
	
	scene_info_			= _info;
	
	is_delete_			= false;
	win_camp_			= EC_Null;
	
	const MemSceneEntry* scene_entry = sResMgr->GetSceneEntry(scene_entry_id_);
	if (!scene_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Invalid scene entry: " << scene_entry_id_;
			
		Destroy();
		
		return false;
	}
	
	scene_entry_ = scene_entry;
	
	for (int i = EC_Start; i < EC_End; ++i)
	{
		FightGroup* fight_group = sObjectPoolMgr->object_pool_fight_group.construct();
		if (!fight_group)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "Object pool construct failed for fight_group";
			
			Destroy();
			
			return false;
		}
		
		ECamp camp = (ECamp)i;
		
		if ( !( fight_group->Init(this, camp) ) )
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "fight_group init failed.";
			
			Destroy();
			
			return false;
		}
		
		MemFightGroup* mem_fight_group = _info->fight_group[camp];
		if (!mem_fight_group)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "Null pointer mem_fight_group";
			
			Destroy();
			
			return false;
		}
		
		for (auto iter = mem_fight_group->fight_hero_vec.begin();
			 iter != mem_fight_group->fight_hero_vec.end();
			 ++iter)
		{
			FightHero* fight_hero = sObjectPoolMgr->object_pool_fight_hero.construct();
			if (!fight_hero)
			{
				BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
					<< "Object pool construct failed for fight hero";
				
				return false;
			}
			
			if ( !( fight_hero->Init( &(**iter), fight_group ) ) )
			{
				BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
					<< "fight_hero init failed.";
			
				Destroy();
				
				return false;
			}
			
			fight_group->AddHero(fight_hero);
		}
		
		fight_group_[camp] = fight_group;
	}
	
	round_index_	= 0;
	
	round_ = sObjectPoolMgr->object_pool_round.construct();
	if (!round_)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Object pool construct failed for round_";
			
		Destroy();
		
		return false;
	}
		
	BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "id = " << id_ << " creator_id = " << creator_id_ << " scene_entry_id = " << scene_entry_id_
		<< " scene_entry_type = " << scene_entry_type_;
	
	
	return true;
}

void Scene::Destroy()
{
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "id = " << id_ << " creator_id = " << creator_id_ << " scene_entry_id = " << scene_entry_id_
		<< " scene_entry_type = " << scene_entry_type_;
	
	for (int i = EC_Start; i < EC_End; ++i)
	{
		fight_group_[i]->Destroy();
		
		if ( fight_group_[i] )
			sObjectPoolMgr->object_pool_fight_group.destroy( fight_group_[i] );
	}
	
	if (round_)
		sObjectPoolMgr->object_pool_round.destroy(round_);
	
	return;
}

//-----------------------------------------------------------------------------
// 每帧更新
//-----------------------------------------------------------------------------
void Scene::Update()
{
	if (is_delete_)
		return;
	
	if ( !fight_group_[EC_Attack] || fight_group_[EC_Attack]->IsDead() )
	{
		win_camp_ = EC_Defence;
		
		OnBattleFinish();
		
		return;
	}
	
	if ( !fight_group_[EC_Defence] || fight_group_[EC_Defence]->IsDead() )
	{
		win_camp_ = EC_Attack;
		
		OnBattleFinish();
		
		return;
	}
	
	fight_group_[EC_Attack]->Attack( fight_group_[EC_Defence] );
	
	return;
}

//-----------------------------------------------------------------------------
// 构建下一回合
//-----------------------------------------------------------------------------
void Scene::BuildNextRound(const int32_t _round_index)
{
	if (!round_)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer round_";
		
		return;
	}
	
	round_->set_round(_round_index);
	
	std::list<FightHero*>& fight_hero_attack_list = round_->get_fight_hero_attack_list();
	
	for (int i = EC_Start; i < EC_End; ++i)
	{
		FightGroup* fight_group = fight_group_[i];
		if (!fight_group)
			continue;
		
		for (auto iter = fight_group->get_fight_hero().begin();
			 iter != fight_group->get_fight_hero().end();
			 ++iter)
		{
			if ( (*iter)->IsDead() )
				continue;
			
			fight_hero_attack_list.push_back( &(**iter) );
		}
	}
	
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | " 
		<< "id = " << id_ << ", scene_entry_id " << get_scene_entry_id() << ", round_index = " << _round_index;
	
	return;
}

//-----------------------------------------------------------------------------
// 每回合结束响应函数
//-----------------------------------------------------------------------------
void Scene::OnRoundFinish()
{
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | " 
		<< "id = " << id_ << ", scene_entry_id " << get_scene_entry_id() << ", round_index = " << round_index_;
	
	if (!round_)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer round_";
		
		return;
	}
	
	++round_index_;
	
	round_->Clear();
	
	BuildNextRound(round_index_);
}

//-----------------------------------------------------------------------------
// 战斗结束响应函数
//-----------------------------------------------------------------------------
void Scene::OnBattleFinish()
{
	is_delete_ = true;
	
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | " 
		<< "id = " << id_ << ", scene_entry_id " << get_scene_entry_id(); 
	
	switch(scene_entry_type_)
	{
		case ESFS_Stage:
		{
			Player* player = sPlayerMgr->get_player_by_id(creator_id_);
			if (!player)
				break;
			
			player->OnAttackFinish(scene_info_);
			break;
		}
		case ESFS_CoupleArena:
		{	
			break;
		}
		default:
		{
			break;
		}
	}
	
	return;
}
