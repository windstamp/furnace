/************************************************************************/
/* @file:	server_event_define.h                                       */
/* @brief:	全服事件相差定义                                            */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-27                                                  */
/* @last:	2017-07-27                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_SERVER_EVENT_DEFINE_H__
#define __WARLORD_GAMESVR_SERVER_EVENT_DEFINE_H__

#include "common.h"

//-----------------------------------------------------------------------------
// 全服事件枚举值
//-----------------------------------------------------------------------------
enum EServerAsycnEvent
{
	ESAE_Null			= 0,
	ESAE_Start			= 1,
	
	ESAE_TimeChange		= ESAE_Start + 0,		// 时间改变
	ESAE_LevelUp		= ESAE_Start + 1,		// 玩家升级
	
	ESAE_End,
};

//-----------------------------------------------------------------------------
// 全服具体事件
//-----------------------------------------------------------------------------
EVENT_BEGIN(TimeChange, ESAE_TimeChange)
	int32_t		period;
	int32_t		misc;
EVENT_END

EVENT_BEGIN(LevelUp, ESAE_LevelUp)
	int64_t		player_id;
	int32_t		pre_level;
	int32_t		cur_level;
EVENT_END

#endif /* __WARLORD_GAMESVR_SERVER_EVENT_DEFINE_H__ */
