// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "object/object_pool_mgr.h"
#include "player/player.h"

#include "container/hero_container.h"

HeroContainer::HeroContainer()
{
}

HeroContainer::~HeroContainer()
{
	std::vector<Hero*>::iterator iter;
	
	for (iter = vec_hero_.begin(); iter != vec_hero_.end(); ++iter)
	{
		sObjectPoolMgr->object_pool_hero.destroy(*iter);
	}
	
	return;
}

bool HeroContainer::Init(Player* _owner)
{
	if (!_owner)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _owner";
		
		return false;
	}
	
	owner_ = _owner;
	
	return true;
}

void HeroContainer::AddHero(const int64_t _type_id, const int64_t _owner_id)
{
	Hero* hero = sObjectPoolMgr->object_pool_hero.construct();
	if (!hero)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Object pool construct failed for hero";
		
		return;
	}
	
	if ( !hero->Init(_type_id, _owner_id, 1) )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "hero Init failed.";
		
		return;
	}
	
	AddHero(hero);
	
	return;
}

void HeroContainer::AddHero(Hero* _hero)
{
	if (!_hero)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _hero";
		
		return;
	}
	
	vec_hero_.push_back(_hero);
	
	map_hero_[ _hero->get_id() ] = _hero;
	
	return;
}

Hero* HeroContainer::GetHeroById(const int64_t _id)
{
	std::map<int64_t, Hero*>::iterator iter;
	
	iter = map_hero_.find(_id);
	
	if ( iter != map_hero_.end() )
		return iter->second;
	
	return NULL;
}

bool HeroContainer::GetHeroByTypeId(const int64_t _hero_type_id, std::vector<Hero*>& _vec_hero)
{
	std::vector<Hero*>::iterator iter;
	
	for (iter = vec_hero_.begin(); iter != vec_hero_.end(); ++iter)
	{
		if ( (*iter)->get_hero_type_id() == _hero_type_id )
			_vec_hero.push_back( &(**iter) );
	}
	
	return true;
}
