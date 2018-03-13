// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "fight/fightable.h"
#include "fight/fight_hero.h"
#include "fight/scene.h"
#include "object/object_pool_mgr.h"

#include "fight/fight_group.h"

//-----------------------------------------------------------------------------
// 构造函数和析构函数
//-----------------------------------------------------------------------------
FightGroup::FightGroup()
{
}

FightGroup::~FightGroup()
{
}

//-----------------------------------------------------------------------------
// 初始化和销毁
//-----------------------------------------------------------------------------
bool FightGroup::Init(Scene* _scene, ECamp _camp)
{
	scene_	= _scene;
	camp_	= _camp;
	
	fight_hero_vec_.clear();
	
	return true;
}

void FightGroup::Destroy()
{
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "camp = " << camp_;
		
	for (auto iter = fight_hero_vec_.begin();
		 iter != fight_hero_vec_.end();
		 ++iter)
	{
		(*iter)->Destroy();
		
		sObjectPoolMgr->object_pool_fight_hero.destroy( &(**iter) );
	}
	
	return;
}

//-----------------------------------------------------------------------------
// 攻击、是否阵亡
//-----------------------------------------------------------------------------
void FightGroup::Attack(FightGroup* _fight_group)
{
	if (!_fight_group)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _fight_group";
		
		return;
	}
	
	if (!scene_)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer scene_";
		
		return;
	}
	
	Round* round = scene_->get_round();
	if (!round)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer round";
		
		return;
	}
	
	if ( round->get_fight_hero_attack_list().empty() )
	{
		scene_->OnRoundFinish();
		
		return;
	}
	
	FightHero* fight_hero = round->ExtractNextAttackFightHero();
	if (!fight_hero)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer fight_hero";
		
		return;
	}
	
	if ( !fight_hero->IsDead() )
		fight_hero->Attack();
	
	return;
}

bool FightGroup::IsDead()
{
	for (auto iter = fight_hero_vec_.begin();
		 iter != fight_hero_vec_.end();
		 ++iter)
	{
		if ( !(*iter)->IsDead() )
			return false;
	}
	
	return true;
}

//-----------------------------------------------------------------------------
// 成员变量的 get/set 函数
//-----------------------------------------------------------------------------
void FightGroup::AddHero(FightHero* _fight_hero)
{
	if (!_fight_hero)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _fight_hero";
		
		return;
	}
	
	fight_hero_vec_.push_back(_fight_hero);
	
	return;
}
