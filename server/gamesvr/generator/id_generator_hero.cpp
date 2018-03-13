// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "define/id_generator_define.h"

#include "generator/id_generator.h"
#include "param/param_mgr.h"

#include "generator/id_generator_hero.h"

//-----------------------------------------------------------------------------
// 构造函数和析构函数
//-----------------------------------------------------------------------------
IdGeneratorHero::IdGeneratorHero()
{
}

IdGeneratorHero::~IdGeneratorHero()
{
}

//-----------------------------------------------------------------------------
// 初始化、销毁
//-----------------------------------------------------------------------------
bool IdGeneratorHero::Init(const int64_t _id, const int32_t _type)
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "id = " << _id << ", type = " << _type;
	
	if (_type != EIT_Hero)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Wrong type: correct = " << EIT_Hero << ", wrong = " << _type;
			
		return false;
	}
	
	return IdGenerator::Init(_id, _type);
}

void IdGeneratorHero::Destroy()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
		
	IdGenerator::Destroy();
}

//-----------------------------------------------------------------------------
// 生成ID
//-----------------------------------------------------------------------------
int64_t IdGeneratorHero::Generate()
{
	pthread_mutex_lock(&lock_);
	
	int64_t ret = 0;
	
	if (id_ == 0)
	{
		int64_t	zone_id = sParamMgr->get_zone_id();
		
		id_	= (zone_id << 40) + ( (int64_t)type_ << 32 ) + 0;
	}
	
	ret = ++id_;
	
	pthread_mutex_unlock(&lock_);
	
	return ret;
}
