/************************************************************************/
/* @file:	time_mgr.h                                                  */
/* @brief:	时间管理器                                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-25                                                  */
/* @last:	2017-07-25                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_COMMON_TIME_MGR_H__
#define __WARLORD_COMMON_TIME_MGR_H__

class TimeMgr
{
public:
	//-------------------------------------------------------------------------
	// 构造函数和析构函数
	//-------------------------------------------------------------------------
	TimeMgr();
	~TimeMgr();

public:
	//-------------------------------------------------------------------------
	// 初始化、销毁
	//-------------------------------------------------------------------------
	bool			Init();
	void			Destroy();
	
public:
	//-------------------------------------------------------------------------
	// 每帧更新
	//-------------------------------------------------------------------------
	void			Update();

public:
	//-------------------------------------------------------------------------
	// 时钟周期是否改变
	//-------------------------------------------------------------------------
	bool			IsSecondChange()	{ return second_change_; }
	bool			IsMinuteChange()	{ return minute_change_; }
	bool			IsHourChange()		{ return hour_change_; }
	bool			IsDayChange()		{ return day_change_; }
	bool			IsWeekChange()		{ return week_change_; }
	bool			IsMonthChange()		{ return month_change_; }
	bool			IsYearChange()		{ return year_change_; }
	
public:
	//-------------------------------------------------------------------------
	// 具体时间单位
	//-------------------------------------------------------------------------
	int32_t			get_year()			{ return tm_ ? tm_->tm_year : 0; }
	int32_t			get_month()			{ return tm_ ? tm_->tm_mon : 0; }
	int32_t			get_week()			{ return 0; }
	int32_t			get_day()			{ return get_year_day(); }
	int32_t			get_hour()			{ return tm_ ? tm_->tm_hour : 0; }
	int32_t			get_minute()		{ return tm_ ? tm_->tm_min : 0; }
	int32_t			get_second()		{ return tm_ ? tm_->tm_sec : 0; }
	
	int32_t			get_year_day()		{ return tm_ ? tm_->tm_yday : 0; }
	int32_t			get_month_day()		{ return tm_ ? tm_->tm_mday : 0; }
	int32_t			get_week_day()		{ return tm_ ? tm_->tm_wday : 0; }
	
public:
	//-------------------------------------------------------------------------
	// 成员变量的 get/set 函数
	//-------------------------------------------------------------------------
	int64_t		get_offset()			{ return offset_; }
	int64_t		get_cur_timestamp()		{ return timestamp_ + offset_; }
	struct tm*	get_tm()				{ return tm_; }
	
	void		set_offset(const int64_t _offset)	{ offset_ = _offset; }
	
private:
	//-------------------------------------------------------------------------
	// 成员变量
	//-------------------------------------------------------------------------
	int64_t		offset_;		// 与基准时间戳的偏移，用于GM修改服务器时间
	int64_t		timestamp_;		// 基准时间戳
	
	struct tm*	tm_;
	
	bool		second_change_;	// 秒是否改变
	bool		minute_change_;	// 分钟是否改变
	bool		hour_change_;	// 小时是否改变
	bool		day_change_;	// 天是否改变
	bool		week_change_;	// 周是否改变
	bool		month_change_;	// 月是否改变
	bool		year_change_;	// 年是否改变
};

#endif /* __WARLORD_COMMON_TIME_MGR_H__ */
