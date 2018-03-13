/************************************************************************/
/* @file:	time_define.h                                               */
/* @brief:	时间相关定义                                                */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-25                                                  */
/* @last:	2017-07-25                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_DEFINE_TIME_DEFINE_H__
#define __WARLORD_DEFINE_TIME_DEFINE_H__

//-----------------------------------------------------------------------------
// 时间周期
//-----------------------------------------------------------------------------
enum ETimePeriod
{
	ETP_Null			= -1,
	
	ETP_Start			= 0,
	ETP_Second			= ETP_Start + 0,
	ETP_Minute			= ETP_Start + 1,
	ETP_Hour			= ETP_Start + 2,
	ETP_Day				= ETP_Start + 3,
	ETP_Week			= ETP_Start + 4,
	ETP_Month			= ETP_Start + 5,
	ETP_Year			= ETP_Start + 6,
	
	ETP_End,
};

#endif /* __WARLORD_DEFINE_TIME_DEFINE_H__ */
