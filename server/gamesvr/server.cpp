// c library
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <error.h>
#include <string.h>

// c++ library
#include <iostream>

// linux library
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

// boost library
//#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
//#include <boost/log/expressions.hpp>
//#include <boost/log/sinks/text_file_backend.hpp>
//#include <boost/log/utility/setup/file.hpp>
//#include <boost/log/utility/setup/common_attributes.hpp>
//#include <boost/log/sources/severity_logger.hpp>
//#include <boost/log/sources/record_ostream.hpp>
namespace logging = boost::log;

// common library
#include "loader/config_mgr.h"
#include "loader/const_mgr.h"

// gamesvr local
#include "define/server_event_define.h"

#include "fight/scene_mgr.h"
#include "object/object_pool_mgr.h"
#include "param/param_mgr.h"
#include "player/player_mgr.h"
#include "resource/res_mgr.h"
#include "util/util_kit_mgr.h"

#include "server.h"

#define BOOST_LOG_DYN_LINK 1

Server::Server()
{
}

Server::~Server()
{
	Destroy();
}

bool Server::Init()
{
	// 静态资源管理器
	if ( !( sResMgr->Init() ) )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "sResMgr Init() failed.";
		
		return false;
	}

	// 静态配置管理器
	if ( !( sConfigMgr->Init() ) )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "sConfigMgr Init() failed.";
		
		return false;
	}
	
	// 静态常量管理器
	if ( !( sConstMgr->Init() ) )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "sConstMgr Init() failed.";
		
		return false;
	}
	
	// 全服公共参数管理器
	if ( !( sParamMgr->Init() ) )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "sParamMgr Init() failed.";
		
		return false;
	}
	
	// 对象池管理器
	if ( !( sObjectPoolMgr->Init() ) )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "sObjectPoolMgr Init() failed.";
		
		return false;
	}
	
	// 公共类管理器
	if ( !( sUtilKitMgr->Init() ) )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "sUtilKitMgr Init() failed.";
		
		return false;
	}
	
	// 战斗场景管理器
	if ( !( sSceneMgr->Init() ) )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "sSceneMgr Init() failed.";
		
		return false;
	}
	
	// 玩家管理器
	if ( !( sPlayerMgr->Init() ) )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "sPlayerMgr Init() failed.";
		
		return false;
	}
	
	return true;
}

void Server::Destroy()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
	
	// 玩家管理器
	sPlayerMgr->Destroy();
	
	// 战斗场景管理器
	sSceneMgr->Destroy();
	
	// 公共类管理器
	sUtilKitMgr->Destroy();
	
	// 对象池管理器
	sObjectPoolMgr->Destroy();
	
	// 全服公共参数管理器
	sParamMgr->Destroy();
	
	// 静态常量管理器
	sConstMgr->Destroy();
	
	// 静态配置管理器
	sConfigMgr->Destroy();
	
	// 静态资源管理器
	sResMgr->Destroy();
	
	return;
}

void Server::Update()
{
	sUtilKitMgr->Update();
	
	sSceneMgr->Update();

	sPlayerMgr->Update();
	
//	sleep(1);

	UpdateTime();
	
	return;
}

void Server::UpdateTime()
{
	TimeMgr* time_mgr = sUtilKitMgr->get_time_mgr();
	if (!time_mgr)
		return;
	
	EventMgr* event_mgr = sUtilKitMgr->get_event_mgr();
	if (!event_mgr)
		return;
	
	if ( time_mgr->IsYearChange() )
	{
		tagEventTimeChange* async_event = new tagEventTimeChange();
		if (!async_event)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "new tagEventTimeChange() failed.";
		}
		else
		{
			async_event->period	= ETP_Year;
			async_event->misc	= time_mgr->get_year();
			
			event_mgr->AddAsyncEvent(async_event);
		}
	}
	
	if ( time_mgr->IsMonthChange() )
	{
		tagEventTimeChange* async_event = new tagEventTimeChange();
		if (!async_event)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "new tagEventTimeChange() failed.";
		}
		else
		{
			async_event->period	= ETP_Month;
			async_event->misc	= time_mgr->get_month();
			
			event_mgr->AddAsyncEvent(async_event);
		}
	}
	
	if ( time_mgr->IsWeekChange() )
	{
		tagEventTimeChange* async_event = new tagEventTimeChange();
		if (!async_event)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "new tagEventTimeChange() failed.";
		}
		else
		{
			async_event->period	= ETP_Week;
			async_event->misc	= time_mgr->get_week();
			
			event_mgr->AddAsyncEvent(async_event);
		}
	}
	
	if ( time_mgr->IsDayChange() )
	{
		tagEventTimeChange* async_event = new tagEventTimeChange();
		if (!async_event)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "new tagEventTimeChange() failed.";
		}
		else
		{
			async_event->period	= ETP_Day;
			async_event->misc	= time_mgr->get_day();
			
			event_mgr->AddAsyncEvent(async_event);
		}
	}
	
	if ( time_mgr->IsHourChange() )
	{
		tagEventTimeChange* async_event = new tagEventTimeChange();
		if (!async_event)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "new tagEventTimeChange() failed.";
		}
		else
		{
			async_event->period	= ETP_Hour;
			async_event->misc	= time_mgr->get_hour();
			
			event_mgr->AddAsyncEvent(async_event);
		}
	}
	
	if ( time_mgr->IsMinuteChange() )
	{
		tagEventTimeChange* async_event = new tagEventTimeChange();
		if (!async_event)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "new tagEventTimeChange() failed.";
		}
		else
		{
			async_event->period	= ETP_Minute;
			async_event->misc	= time_mgr->get_minute();
			
			event_mgr->AddAsyncEvent(async_event);
		}
	}
		
	if ( time_mgr->IsSecondChange() )
	{
		tagEventTimeChange* async_event = new tagEventTimeChange();
		if (!async_event)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "new tagEventTimeChange() failed.";
		}
		else
		{
			async_event->period	= ETP_Second;
			async_event->misc	= time_mgr->get_second();
			
			event_mgr->AddAsyncEvent(async_event);
		}
	}
	
	return;
}

int main(int argc, char* argv[])
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "===== gamesvr start =====";

	Server server;
	if ( !( server.Init() ) )
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "server Init failed.";
		
		return -1;
	}
	
	while(true)
	{
		server.Update();
	}
	
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "===== gamesvr stop =====";
	
	return 0;
}
