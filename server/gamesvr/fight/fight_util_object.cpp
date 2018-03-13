// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "object/object_pool_mgr.h"
#include "resource/res_mgr.h"

#include "fight/fight_util_object.h"

//-----------------------------------------------------------------------------
// 战斗英雄基础数据
//-----------------------------------------------------------------------------
MemFightHero::MemFightHero()
{
}

MemFightHero::MemFightHero(const MemFightHero* rhs)
{
	if (!rhs)
		return;
	
	if (this == rhs)
		return;
	
	this->hero_id	= rhs->hero_id;
	this->level		= rhs->level;
	this->pos		= rhs->pos;
	this->owner_id	= rhs->owner_id;
	
	std::copy(rhs->fight_att_map.begin(),
			  rhs->fight_att_map.end(),
			  inserter(this->fight_att_map, this->fight_att_map.begin() ) );
	
	this->hero_entry	= rhs->hero_entry;
	
	if (!hero_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Invalid entry hero " << hero_type_id;
	}
	
	return;
}

MemFightHero& MemFightHero::operator=(const MemFightHero* rhs)
{
	if (!rhs)
		return *this;
	
	if (this == rhs)
		return *this;
	
	this->hero_id	= rhs->hero_id;
	this->level		= rhs->level;
	this->pos		= rhs->pos;
	this->owner_id	= rhs->owner_id;
	
	std::copy(rhs->fight_att_map.begin(),
			  rhs->fight_att_map.end(),
			  inserter(this->fight_att_map, this->fight_att_map.begin() ) );
	
	this->hero_entry	= rhs->hero_entry;
	
	if (!hero_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Invalid entry hero " << hero_type_id;
	}
	
	return *this;
}

bool MemFightHero::Init(const int64_t _hero_id, const int64_t _hero_type_id, const int32_t _level, const int32_t _pos, const int64_t _owner_id)
{
	hero_id			= _hero_id;
	hero_type_id	= _hero_type_id;
	level			= _level;
	pos				= _pos;
	owner_id		= _owner_id;
	
	fight_att_map.clear();
	
	hero_entry = sResMgr->GetHeroEntry(hero_type_id);
	if (!hero_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Invalid entry hero " << hero_type_id;
		
		return false;
	}
	
	return true;
}

//-----------------------------------------------------------------------------
// 战斗阵容基础数据
//-----------------------------------------------------------------------------
MemFightGroup::MemFightGroup()
{
	Init();
}

MemFightGroup::~MemFightGroup()
{
	std::vector<MemFightHero*>::iterator iter;
	std::vector<MemFightHero*>::iterator iter_begin	= fight_hero_vec.begin();
	std::vector<MemFightHero*>::iterator iter_end	= fight_hero_vec.end();
	
	for (iter = iter_begin; iter != iter_end; ++iter)
	{
		sObjectPoolMgr->object_pool_mem_fight_hero.destroy(*iter);
	}
}

MemFightGroup::MemFightGroup(const MemFightGroup* rhs)
{
	if (!rhs)
		return;
	
	if (this == rhs)
		return;
	
	this->param1	= rhs->param1;
	this->param2	= rhs->param2;
	this->param3	= rhs->param3;
	
	std::copy(rhs->fight_hero_vec.begin(),
			  rhs->fight_hero_vec.end(),
			  back_inserter(this->fight_hero_vec) );
}

MemFightGroup& MemFightGroup::operator=(const MemFightGroup* rhs)
{
	if (!rhs)
		return *this;
	
	if (this == rhs)
		return *this;
	
	this->param1	= rhs->param1;
	this->param2	= rhs->param2;
	this->param3	= rhs->param3;
	
	std::copy(rhs->fight_hero_vec.begin(),
			  rhs->fight_hero_vec.end(),
			  back_inserter(this->fight_hero_vec) );
			  
	return *this;
}

bool MemFightGroup::Init()
{
	param1	= 0;
	param2	= 0;
	param3	= 0;
	
	fight_hero_vec.clear();
	
	return true;
}

//-----------------------------------------------------------------------------
// 各个战斗场景相关的杂项信息
//-----------------------------------------------------------------------------
MemSceneMiscInfo::MemSceneMiscInfo()
{
	Init();
}

void MemSceneMiscInfo::Init()
{
	bzero( this, sizeof(*this) );
}

//-----------------------------------------------------------------------------
// 进入战斗场景的数据结构
//-----------------------------------------------------------------------------
MemEnterSceneInfo::MemEnterSceneInfo()
{
	Init();
}

MemEnterSceneInfo::~MemEnterSceneInfo()
{
	for (int i = EC_Null + 1; i < EC_End; ++i)
	{
		sObjectPoolMgr->object_pool_mem_fight_group.destroy( fight_group[i] );
	}
}

void MemEnterSceneInfo::Init()
{
	serial				= 0;
	creator_id			= 0;
	scene_entry_id		= 0;
	scene_entry_type	= 0;
	
	for (int i = EC_Null; i < EC_End; ++i)
		fight_group[i] = NULL;
	
	misc_info.Init();
}
