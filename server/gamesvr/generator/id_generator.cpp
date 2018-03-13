// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "generator/id_generator.h"

//-----------------------------------------------------------------------------
// 构造函数和析构函数
//-----------------------------------------------------------------------------
IdGenerator::IdGenerator()
{
}

IdGenerator::~IdGenerator()
{
}

//-----------------------------------------------------------------------------
// 初始化、销毁
//-----------------------------------------------------------------------------
bool IdGenerator::Init(const int64_t _id, const int32_t _type)
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "id = " << _id << ", type = " << _type;
	
	id_		= _id;
	type_	= _type;
	
	if (pthread_mutex_init(&lock_, NULL) != 0)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "pthread_mutex_init failed.";
		
		return false;
	}
	
	return true;
}

void IdGenerator::Destroy()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
		
	pthread_mutex_destroy(&lock_);
}
