// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "time/time_mgr.h"

#include "test/test_time.h"

void test_time()
{
	TimeMgr time_mgr;
	
	bool ret = time_mgr.Init();
	if (!ret)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "time_mgr.Init() failed.";
	
		return;
	}
	
	for (int i = 0; i < 5; ++i)
	{
		sleep(1);
		
		time_mgr.Update();
		
		if ( time_mgr.IsYearChange() )
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "year change: " << time_mgr.get_year();
		}
		
		if ( time_mgr.IsMonthChange() )
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "month change: " << time_mgr.get_month();
		}
		
		if ( time_mgr.IsWeekChange() )
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "week change: " << time_mgr.get_week();
		}
		
		if ( time_mgr.IsDayChange() )
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "day change: " << time_mgr.get_day();
		}
		
		if ( time_mgr.IsHourChange() )
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "hour change: " << time_mgr.get_hour();
		}
		
		if ( time_mgr.IsMinuteChange() )
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "minute change: " << time_mgr.get_minute();
		}
		
		if ( time_mgr.IsSecondChange() )
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "second change: " << time_mgr.get_second();
		}	
	}
	
}
