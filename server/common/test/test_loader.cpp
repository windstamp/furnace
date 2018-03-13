// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "loader/config_mgr.h"
#include "loader/const_mgr.h"

#include "test/test_loader.h"

void test_loader()
{	
	sConfigMgr->Init();
		
	sConstMgr->Init();
}
