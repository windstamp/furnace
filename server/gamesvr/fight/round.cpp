// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "fight/round.h"

//-----------------------------------------------------------------------------
// 构造函数和析构函数
//-----------------------------------------------------------------------------
Round::Round()
{
}

Round::~Round()
{
}

//-----------------------------------------------------------------------------
// 初始化和销毁
//-----------------------------------------------------------------------------
bool Round::Init(const int32_t _round)
{
	round_	= _round;
	
	return true;
}

void Round::Destroy()
{
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "round = " << round_;
}

void Round::Clear()
{
	round_	= 0;
	
	fight_hero_attackk_list_.clear();
}

//-----------------------------------------------------------------------------
// 获取下一个攻击英雄
//-----------------------------------------------------------------------------
FightHero* Round::ExtractNextAttackFightHero()
{
	if ( fight_hero_attackk_list_.empty() )
		return NULL;
	
	FightHero* fight_hero = fight_hero_attackk_list_.front();
	
	fight_hero_attackk_list_.pop_front();
	
	return fight_hero;
}
