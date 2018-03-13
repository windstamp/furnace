// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "define/event_define.h"

#include "event/event_mgr.h"

#include "test/test_event.h"

void asycn_event_handle_test_func(tagEventBase* _event_base)
{
	if (!_event_base)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "NULL pointer _event_base";
		
		return;
	}
	
	tagEventAsyncTest* event = (tagEventAsyncTest*)_event_base;	
	if (!event)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "NULL pointer event";
		
		return;
	}
	
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "value = " << event->value;
			
	return;	
}

void sycn_event_handle_test_func(tagEventBase& _event_base)
{
	tagEventSyncTest* event = (tagEventSyncTest*)&_event_base;	
	if (!event)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "NULL pointer event";
		
		return;
	}
	
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "value = " << event->value;
	
	return;
}

void test_event()
{
	EventMgr event_mgr;
	
	bool ret = event_mgr.Init();
	if (!ret)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "event_mgr.Init() failed.";
	
		return;
	}
	
	event_mgr.RegisterAsyncEventHandler(ETAE_AsyncTest, asycn_event_handle_test_func);
	event_mgr.RegisterSyncEventHandler(ETSE_SyncTest, sycn_event_handle_test_func);
	
	int count = 0;
	for (int i = 0; i < 3; ++i)
	{
		event_mgr.Update();
		
		tagEventAsyncTest* async_event = new tagEventAsyncTest();
		if (!ret)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "new tagEventAsyncTest() failed.";
		
			return;
		}
		
		async_event->value = ++count;
		
		event_mgr.AddAsyncEvent(async_event);

		tagEventSyncTest sync_event;
		sync_event.value = ++count;
		
		event_mgr.SendSyncEvent(sync_event);		
	}
	
	return;
}
