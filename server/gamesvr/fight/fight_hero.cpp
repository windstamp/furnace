// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "define/error_code.h"
#include "define/gamesvr_error_code.h"

#include "fight/fightable.h"
#include "fight/fight_helper.h"
#include "fight/fight_util_object.h"
#include "fight/skill.h"
#include "object/hero.h"
#include "object/object_pool_mgr.h"

#include "fight/fight_hero.h"

//-----------------------------------------------------------------------------
// 构造函数和析构函数
//-----------------------------------------------------------------------------
FightHero::FightHero()
{
}

FightHero::~FightHero()
{
}

//-----------------------------------------------------------------------------
// 初始化和销毁
//-----------------------------------------------------------------------------
bool FightHero::Init(const MemHeroEntry* _hero_entry, FightGroup* _fight_group, const int64_t _owner_id, const int32_t _pos)
{
	if (!_hero_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _hero_entry";
		
		return false;
	}
	
	if (!_fight_group)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _fight_group";
		
		return false;
	}
	
	fight_group_ = _fight_group;
	
	const MemHeroBaseEntry* hero_base_entry = _hero_entry->base_entry;
	if (!hero_base_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer hero_base_entry";
		
		return false;
	}
	
	const MemSkillEntry* common_skill_entry = hero_base_entry->common_skill_entry;
	if (!common_skill_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer common_skill_entry";
		
		return false;
	}
	
	Skill* common_skill = sObjectPoolMgr->object_pool_skill.construct();
	if (!common_skill)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Object pool construct failed for skill";
		
		return false;
	}
	
	common_skill->Init(common_skill_entry);
	
	const MemSkillEntry* profound_skill_entry = hero_base_entry->profound_skill_entry;
	if (!profound_skill_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer profound_skill_entry";
		
		return false;
	}
	
	Skill* profound_skill = sObjectPoolMgr->object_pool_skill.construct();
	if (!profound_skill)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Object pool construct failed for skill";
		
		return false;
	}
	
	profound_skill->Init(profound_skill_entry);
	
	owner_id_	= _owner_id;
	pos_		= _pos;
	
	hero_entry_ = _hero_entry;
	
	fight_helper::BuildHeroAtt(fight_att_, _hero_entry, owner_id_);
	
	return true;
}

bool FightHero::Init(MemFightHero* _fight_hero, FightGroup* _fight_group)
{
	if (!_fight_hero)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _fight_hero";
		
		return false;
	}
		
	if (!_fight_group)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _fight_group";
		
		return false;
	}
	
	fight_group_ = _fight_group;
	
	const MemHeroEntry*	hero_entry = _fight_hero->hero_entry;
	if (!hero_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer hero_entry";
		
		return false;
	}
	
	hero_entry_ = hero_entry;
	
	const MemHeroBaseEntry* hero_base_entry = hero_entry->base_entry;
	if (!hero_base_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer hero_base_entry";
		
		return false;
	}
	
	const MemSkillEntry* common_skill_entry = hero_base_entry->common_skill_entry;
	if (!common_skill_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer common_skill_entry";
		
		return false;
	}
	
	Skill* common_skill = sObjectPoolMgr->object_pool_skill.construct();
	if (!common_skill)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Object pool construct failed for skill";
		
		return false;
	}
	
	common_skill->Init(common_skill_entry);
	
	const MemSkillEntry* profound_skill_entry = hero_base_entry->profound_skill_entry;
	if (!profound_skill_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer profound_skill_entry";
		
		return false;
	}
	
	Skill* profound_skill = sObjectPoolMgr->object_pool_skill.construct();
	if (!profound_skill)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Object pool construct failed for skill";
		
		return false;
	}
	
	profound_skill->Init(profound_skill_entry);
	
	owner_id_	= _fight_hero->owner_id;
	
	fight_hero_	= _fight_hero;
	
	fight_helper::BuildHeroAtt(fight_att_, _fight_hero, owner_id_);
	
	return true;
}

bool FightHero::Init(Hero* _hero, FightGroup* _fight_group, int64_t owner_id)
{
	if (!_hero)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _hero";
		
		return false;
	}
		
	if (!_fight_group)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _fight_group";
		
		return false;
	}
	
	fight_group_ = _fight_group;
	
	const MemHeroEntry*	hero_entry = _hero->get_hero_entry();
	if (!hero_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer hero_entry";
		
		return false;
	}
	
	hero_entry_ = hero_entry;
	
	const MemHeroBaseEntry* hero_base_entry = hero_entry->base_entry;
	if (!hero_base_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer hero_base_entry";
		
		return false;
	}
	
	const MemSkillEntry* common_skill_entry = hero_base_entry->common_skill_entry;
	if (!common_skill_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer common_skill_entry";
		
		return false;
	}
	
	Skill* common_skill = sObjectPoolMgr->object_pool_skill.construct();
	if (!common_skill)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Object pool construct failed for skill";
		
		return false;
	}
	
	common_skill->Init(common_skill_entry);
	
	const MemSkillEntry* profound_skill_entry = hero_base_entry->profound_skill_entry;
	if (!profound_skill_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer profound_skill_entry";
		
		return false;
	}
	
	Skill* profound_skill = sObjectPoolMgr->object_pool_skill.construct();
	if (!profound_skill)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Object pool construct failed for skill";
		
		return false;
	}
	
	profound_skill->Init(profound_skill_entry);
	
	owner_id_ = owner_id;
	
	hero_ = _hero;
	hero_entry_ = _hero->get_hero_entry();
	
	fight_helper::BuildHeroAtt(fight_att_, _hero, owner_id_);
	
	return true;
}

void FightHero::Destroy()
{
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "owner_id = " << owner_id_ << " pos = " << pos_ << " hero_type_id = " << get_hero_type_id();
	
	//if (common_skill_)
		// sObjectPoolMgr->object_pool_skill.destroy(common_skill_);
	
	// if (profound_skill_)
		// sObjectPoolMgr->object_pool_skill.destroy(profound_skill_);
	
	return;
}

//-----------------------------------------------------------------------------
// 攻击、是否阵亡
//-----------------------------------------------------------------------------
void FightHero::Attack()
{
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "hero <" << get_hero_type_id() << ">";
	
	std::list<FightHero*> fight_hero_target;
	
	GetAttackTarget(fight_hero_target);
	
	for (auto iter = fight_hero_target.begin();
		 iter != fight_hero_target.end();
		 ++iter)
	{
		Attack( &(**iter) );
	}
	
	return;
}

bool FightHero::IsDead()
{
	auto iter = fight_att_.find( (int32_t)EHA_CurHP );
	
	if ( iter == fight_att_.end() )
		return true;
	
	if (iter->second == 0)
		return true;
	
	return false;
}

//-----------------------------------------------------------------------------
// 攻击、是否阵亡
//-----------------------------------------------------------------------------
void FightHero::GetAttackTarget(std::list<FightHero*>& _fight_hero_target)
{
	if (!fight_group_)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer fight_group_";
		
		return;
	}
	
	Scene* scene = fight_group_->get_scene();
	if (!scene)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer scene";
		
		return;
	}
	
	FightGroup** fight_group_array = scene->get_fight_group();
	if (!fight_group_array)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer fight_group_array";
		
		return;
	}	
	
	ECamp attack_cmap = fight_group_->get_camp();
	ECamp target_camp = EC_Null;
	
	if (attack_cmap == EC_Attack)
		target_camp = EC_Defence;
	else if (attack_cmap == EC_Defence)
		target_camp = EC_Attack;
	
	for (int i = EC_Start; i < EC_End; ++i)
	{
		if (i != target_camp)
			continue;
		
		FightGroup* fight_group = fight_group_array[i];
		//FightGroup* fight_group = scene->get_fight_group(i);
		if (!fight_group)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "Null pointer fight_group:" << i;
			
			continue;
		}
		
		for (auto iter = fight_group->get_fight_hero().begin();
			 iter != fight_group->get_fight_hero().end();
			 ++iter)
		{
			if ( (*iter)->IsDead() )
				continue;
			
			_fight_hero_target.push_back( &(**iter) );
			
			return;
		}
	}
	
	return;
}

void FightHero::Attack(FightHero* _target_fight_hero)
{
	if (!_target_fight_hero)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _target_fight_hero";
		
		return;
	}
	
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "hero <" << get_hero_type_id() << "> attacked hero <" << _target_fight_hero->get_hero_type_id() << ">";
	
	std::map<int32_t, int32_t>& attack_fight_att = fight_att_;
	std::map<int32_t, int32_t>& target_fight_att = _target_fight_hero->get_fight_att();
	
	auto attack_iter = attack_fight_att.find(EHA_AttackPower);
	if ( attack_iter == attack_fight_att.end() )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "No att " << EHA_AttackPower;
			
		return;
	}
	
	auto target_iter = target_fight_att.find(EHA_CurHP);
	if ( target_iter == target_fight_att.end() )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "No att " << EHA_CurHP;
		
		return;
	}
	
	LogFightAtt();
	_target_fight_hero->LogFightAtt();
	
	target_iter->second -= attack_iter->second * 1;
	if (target_iter->second < 0)
		target_iter->second = 0;
	
	OnAttChange();
	_target_fight_hero->OnAttChange();
	
	LogFightAtt();
	_target_fight_hero->LogFightAtt();
}

//-----------------------------------------------------------------------------
// 响应函数
//-----------------------------------------------------------------------------
void FightHero::OnAttChange()
{
	auto target_iter = fight_att_.find(EHA_CurHP);
	
	if ( target_iter != fight_att_.end() )
	{
		if (target_iter->second == 0)
		{
			OnDead();
		}
	}
}

void FightHero::OnDead()
{
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "hero is dead: hero_type_id = " << get_hero_type_id();
	
	return;
}

//-----------------------------------------------------------------------------
// 日志函数
//-----------------------------------------------------------------------------
void FightHero::LogFightAtt()
{
	int32_t attack_power = 0, defence_melee = 0, defence_magic = 0, cur_hp = 0, cur_speed = 0;
	
	for (auto iter = fight_att_.begin();
		 iter != fight_att_.end();
		 ++iter)
	{
		switch (iter->first)
		{
			case EHA_AttackPower:
				attack_power = iter->second;
				break;
			case EHA_DefenceMelee:
				defence_melee = iter->second;
				break;
			case EHA_DefenceMagic:
				defence_magic = iter->second;
				break;
			case EHA_CurHP:
				cur_hp = iter->second;
				break;
			case EHA_CurSpeed:
				cur_speed = iter->second;
				break;
			default:
				break;
		}
	}
	
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "hero <" << get_hero_type_id() << "> with:"
		<< " attack_power = " << attack_power
		<< " defence_melee = " << defence_melee
		<< " defence_magic = " << defence_magic
		<< " cur_hp = " << cur_hp
		<< " cur_speed = " << cur_speed;
	
	return;
}

//-----------------------------------------------------------------------------
// 成员变量的 get/set 函数
//-----------------------------------------------------------------------------
void FightHero::add_rage(const int32_t _rage)
{
	rage_ += _rage;
	
	return;
}
