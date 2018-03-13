// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "fight/fight_util_object.h"
#include "fight/scene.h"
#include "player/player.h"

#include "object/object_pool_mgr.h"

//-----------------------------------------------------------------------------
// 初始化、销毁
//-----------------------------------------------------------------------------
bool ObjectPoolMgr::Init()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
	
	return true;
}

void ObjectPoolMgr::Destroy()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
	
	return;
}
