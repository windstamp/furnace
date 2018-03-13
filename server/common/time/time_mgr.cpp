#include <time.h>

// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "time/time_mgr.h"

//-----------------------------------------------------------------------------
// 构造函数和析构函数
//-----------------------------------------------------------------------------
TimeMgr::TimeMgr()
{
}

TimeMgr::~TimeMgr()
{
}

//-----------------------------------------------------------------------------
// 初始化、销毁
//-----------------------------------------------------------------------------
bool TimeMgr::Init()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
	
	offset_		= 0;
	
	time_t cur_timestamp		= time(NULL) + (time_t)offset_;
	
	timestamp_	= (int64_t)cur_timestamp;
	tm_			= localtime(&cur_timestamp);
	
	second_change_	= false;
	minute_change_	= false;
	hour_change_	= false;
	day_change_		= false;
	week_change_	= false;
	month_change_	= false;
	year_change_	= false;
	
	return true;
}

void TimeMgr::Destroy()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
	
	if (tm_)
		free(tm_);
}

//-----------------------------------------------------------------------------
// 每帧更新
//-----------------------------------------------------------------------------
void TimeMgr::Update()
{
	if (!tm_)
	{
		BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "NULL pointer tm_";
		
		return;
	}
	
	time_t	last_timestamp	= timestamp_;
	
	int32_t	last_year		= tm_->tm_year;
	int32_t	last_mon		= tm_->tm_mon;
	int32_t	last_mday		= tm_->tm_mday;
	int32_t	last_hour		= tm_->tm_hour;
	int32_t	last_min		= tm_->tm_min;
	int32_t	last_sec		= tm_->tm_sec;
	
	time_t cur_timestamp = time(NULL) + offset_;
	
	double diff_timestamp	= difftime(cur_timestamp, last_timestamp);
	
	if ( diff_timestamp <= 1.000001 )
		return;
	
	timestamp_	= (int64_t)cur_timestamp;
	tm_			= localtime(&cur_timestamp);
	
	year_change_	= (tm_->tm_year != last_year) ? true : false;
	month_change_	= (year_change_ || tm_->tm_mon != last_mon) ? true : false;
	day_change_		= (month_change_ || tm_->tm_mday != last_mday) ? true : false;
	hour_change_	= (day_change_ || tm_->tm_hour != last_hour) ? true : false;
	minute_change_	= (hour_change_ || tm_->tm_min != last_min) ? true : false;
	second_change_	= (minute_change_ || tm_->tm_sec != last_sec) ? true : false;
	
	week_change_	= (day_change_ && tm_->tm_wday == 0) ? true : false;
	
	return;
}
