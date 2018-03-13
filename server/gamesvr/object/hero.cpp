// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "define/gamesvr_error_code.h"

#include "player/player.h"
#include "player/player_mgr.h"
#include "resource/res_mgr.h"

#include "hero.h"

Hero::Hero()
{
}

Hero::~Hero()
{
}

Hero::Hero(const Hero& rhs)
{
	if (this == &rhs)
		return;
	
	this->id_			= rhs.id_;
	this->pos_			= rhs.pos_;
	this->owner_id_		= rhs.owner_id_;
	
	this->hero_entry_	= rhs.hero_entry_;
	
	if (!hero_entry_)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Invalid hero entry: " << hero_type_id_;
	}
	
	return;
}

Hero& Hero::operator=(const Hero& rhs)
{
	if (this == &rhs)
		return *this;
	
	this->id_			= rhs.id_;
	this->pos_			= rhs.pos_;
	this->owner_id_		= rhs.owner_id_;
	
	this->hero_entry_	= rhs.hero_entry_;
	
	if (!hero_entry_)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Invalid hero entry: " << hero_type_id_;
	}
	
	return *this;
}

bool Hero::Init(const int64_t _hero_type_id, const int64_t _owner_id, const int32_t _pos)
{
	hero_type_id_ = _hero_type_id;
	
	const MemHeroEntry* hero_entry = sResMgr->GetHeroEntry(_hero_type_id);
	
	if (!hero_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Invalid hero entry: " << _hero_type_id;
		
		return false;
	}
	
	return Init(hero_entry, _owner_id, _pos);
}

bool Hero::Init(const MemHeroEntry* _hero_entry, const int64_t _owner_id, const int32_t _pos)
{
	if (!_hero_entry)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _hero_entry";
		
		return false;
	}
	
	owner_id_		= _owner_id;
	pos_			= _pos;
	
	hero_entry_ 	= _hero_entry;
	
	hero_type_id_	= hero_entry_->id;
	
	id_ = sPlayerMgr->gen_hero_seiral();
	
	return true;
}

bool Hero::GetAtt(std::map<int32_t, int32_t>& _fight_att)
{
	if (!hero_entry_)
	{
		BOOST_LOG_TRIVIAL(error) << "Null pointer hero_entry_";
		
		return false;
	}
	
	bool ret = true;
	
	hero_entry_->get_fight_att(_fight_att);
	
	return ret;
}
