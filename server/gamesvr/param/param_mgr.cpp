// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "param/param_mgr.h"

//-----------------------------------------------------------------------------
// 初始化、销毁
//-----------------------------------------------------------------------------
bool ParamMgr::Init()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
	
	param_info_.zone_id			= 1035;
	param_info_.group_id		= 1035;
	param_info_.open_timestamp	= 0;
	
	return true;
}

void ParamMgr::Destroy()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
		
	return;
}
