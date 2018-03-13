/************************************************************************/
/* @file:	fight_define.h                                              */
/* @brief:	战斗相关定义                                                */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-18                                                  */
/* @last:	2017-06-24                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_PARAM_DEFINE_H__
#define __WARLORD_GAMESVR_PARAM_DEFINE_H__

#include "common.h"

//-----------------------------------------------------------------------------
// 全服公共参数
//-----------------------------------------------------------------------------
struct MemParamInfo
{
	int64_t		zone_id;			// 服务器区号
	int64_t		group_id;			// 服务器组号 - 跨区
	int64_t		open_timestamp;		// 开服时间戳
};

#endif	/* #ifndef __WARLORD_GAMESVR_PARAM_DEFINE_H__ */
