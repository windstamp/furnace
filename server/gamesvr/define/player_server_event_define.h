/************************************************************************/
/* @file:	player_event_define.h                                       */
/* @brief:	玩家事件相差定义                                            */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-27                                                  */
/* @last:	2017-07-27                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_PLAYER_EVENT_DEFINE_H__
#define __WARLORD_GAMESVR_PLAYER_EVENT_DEFINE_H__

#include "common.h"

//-----------------------------------------------------------------------------
// 玩家事件枚举值
//-----------------------------------------------------------------------------
enum EPlayerEvent
{
	EPE_Null			= 0,
	EPE_Start			= 1,
	
	EPE_MasterLevelUp	= EPE_Start + 0,		// 主角升级
	EPE_HeroLevelUp		= EPE_Start + 1,		// 英雄升级
	
	EPE_End,
};

//-----------------------------------------------------------------------------
// 玩家具体事件
//-----------------------------------------------------------------------------
EVENT_BEGIN(MasterLevelUp, EPE_MasterLevelUp)
	int64_t		player_id;
	int32_t		pre_level;
	int32_t		cur_level;
EVENT_END

EVENT_BEGIN(HeroLevelUp, EPE_HeroLevelUp)
	int64_t		player_id;
	int32_t		pre_level;
	int32_t		cur_level;
EVENT_END

#endif /* __WARLORD_GAMESVR_PLAYER_EVENT_DEFINE_H__ */
