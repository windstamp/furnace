// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "container/hero_container.h"
#include "fight/fight_util_object.h"
#include "object/hero.h"
#include "object/object_pool_mgr.h"
#include "player/player.h"
#include "resource/res_mgr.h"

#include "fight/fight_helper.h"

NAMESPACE_BEGIN(fight_helper)

bool UpdateHeroAtt(const std::map<int32_t, int32_t>& _src_fight_att, std::map<int32_t, int32_t>& _dst_fight_att)
{
	for (auto iter_1 = _src_fight_att.begin();
		 iter_1 != _src_fight_att.end();
		 ++iter_1)
	{
		auto iter_2 = _dst_fight_att.find(iter_1->first);
		
		if ( iter_2 == _dst_fight_att.end() )
		{
			_dst_fight_att[iter_1->first] = iter_1->second;
		}
		else
		{
			iter_2->second += iter_1->second;
		}
	}
	
	return true;
}

bool BuildHeroAtt(std::map<int32_t, int32_t>& _fight_att, const MemHeroEntry* _entry, int64_t _owner_id)
{
	if (!_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _entry";
		
		return false;
	}
	
	bool ret = true;
	
	_entry->get_fight_att(_fight_att);
	
	_fight_att[EHA_CurHP] = _fight_att[EHA_MaxHp];
	_fight_att[EHA_CurSpeed] = _fight_att[EHA_Speed];
	
	return ret;
}

bool BuildHeroAtt(std::map<int32_t, int32_t>& _fight_att, Hero* _hero, const int64_t _owner_id)
{
	if (!_hero)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _hero";
		
		return false;
	}
	
	bool ret = true;
	
	ret = _hero->GetAtt(_fight_att);
	
	_fight_att[EHA_CurHP] = _fight_att[EHA_MaxHp];
	_fight_att[EHA_CurSpeed] = _fight_att[EHA_Speed];
	
	return ret;
}

bool BuildHeroAtt(std::map<int32_t, int32_t>& _fight_att, MemFightHero* _mem_fight_hero, int64_t _owner_id)
{
	if (!_mem_fight_hero)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _mem_fight_hero";
		
		return false;
	}
	
	bool ret = true;
	
	ret = UpdateHeroAtt(_mem_fight_hero->fight_att_map, _fight_att);
	
	_fight_att[EHA_CurHP] = _fight_att[EHA_MaxHp];
	_fight_att[EHA_CurSpeed] = _fight_att[EHA_Speed];
	
	return ret;
}

bool BuildFightGroup(MemFightGroup* _dst_fight_group, Player* _player)
{
	if (!_dst_fight_group)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _dst_fight_group";
		
		return false;
	}
	
	if (!_player)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _player";
		
		return false;
	}
	
	bool ret = true;
	
	if ( !_dst_fight_group->Init() )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "_dst_fight_group Init() failed.";
		
		return false;
	}
	
	std::vector<Hero*>& vec_hero = _player->get_hero_container().get_vec_hero();
	
	std::vector<Hero*>::iterator iter;
	for (iter = vec_hero.begin(); iter != vec_hero.end(); ++iter)
	{
		MemFightHero* mem_fight_hero = sObjectPoolMgr->object_pool_mem_fight_hero.construct();
		if (!mem_fight_hero)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "Object pool construct failed for mem_fight_hero";
			
			return false;
		}
		
		if ( !mem_fight_hero->Init( (*iter)->get_id(), (*iter)->get_hero_type_id(), -1, -1, _player->get_id() ) )
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "mem_fight_hero init failed.";
			
			return false;
		}
		
		BuildHeroAtt( mem_fight_hero->fight_att_map, &(**iter), _player->get_id() );
		
		_dst_fight_group->fight_hero_vec.push_back(mem_fight_hero);
	}
	
	return ret;
}

bool BuildFightGroup(MemFightGroup* _dst_fight_group, int64_t _fight_group_id)
{
	if (!_dst_fight_group)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _dst_fight_group";
		
		return false;
	}
	
	bool ret = true;
	
	if ( !_dst_fight_group->Init() )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "_dst_fight_group Init() failed.";
		
		return false;
	}
	
	const MemHeroGroupEntry* hero_group_entry = sResMgr->GetHeroGroupEntry(_fight_group_id);
	if (!hero_group_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Invalid hero group entry: " << _fight_group_id;
		
		return false;
	}
	
	std::map<int32_t, const MemHeroEntry*>::const_iterator iter;
	for (iter = hero_group_entry->hero_entrys.begin();
		 iter != hero_group_entry->hero_entrys.end();
		 ++iter)
	{
		MemFightHero* mem_fight_hero = sObjectPoolMgr->object_pool_mem_fight_hero.construct();
		if (!mem_fight_hero)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "Object pool construct failed for mem_fight_hero";
			
			return false;
		}
		
		if ( !mem_fight_hero->Init(-1, iter->second->id, -1, iter->first, 0) )
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "mem_fight_hero init failed.";
			
			return false;
		}
		
		BuildHeroAtt(mem_fight_hero->fight_att_map, iter->second, 0);
		
		_dst_fight_group->fight_hero_vec.push_back(mem_fight_hero);
	}
	
	return ret;
}

bool BuildFightGroup(MemFightGroup* _dst_fight_group, MemFightGroup* _src_fight_group)
{
	if (!_dst_fight_group)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _dst_fight_group";
		
		return false;
	}
	
	if (!_src_fight_group)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _src_fight_group";
		
		return false;
	}
	
	bool ret = true;
	
	_dst_fight_group = _src_fight_group;
	
	return ret;
}

NAMESPACE_END(fight_helper)
