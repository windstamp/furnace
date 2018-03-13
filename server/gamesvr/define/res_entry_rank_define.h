/************************************************************************/
/* @file:	res_entry_rank_define.h                                     */
/* @brief:	排行榜静态资源项属性定义                                        */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-03-28                                                  */
/* @last:	2017-03-28                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_RES_ENTRY_RANK_DEFINE_H__
#define __WARLORD_GAMESVR_RES_ENTRY_RANK_DEFINE_H__

#include "common.h"

//-----------------------------------------------------------------------------
// 排行榜类型
//-----------------------------------------------------------------------------
enum ERankType
{
	ERT_Null		= 0,
	ERT_PlayerLevel	= 1,	// 玩家等级排行榜
	ERT_PlayerPower	= 2,	// 玩家战力排行榜
	ERT_GuildLevel	= 3,	// 公会等级排行榜
	ERT_End,
};

//-----------------------------------------------------------------------------
// 排行榜重置方式
//-----------------------------------------------------------------------------
enum ERankResetType
{
	ERRT_Null	= 0,	// 
	ERRT_None	= 1,	// 不重置
	ERRT_Day	= 2,	// 每日重置
	ERRT_End,
};

//-----------------------------------------------------------------------------
// 排行榜静态配置属性
//-----------------------------------------------------------------------------
struct MemRankEntry
{
	int64_t		id;			// 排行榜静态ID (ERankType)
	int32_t		reset_type;		// 排行榜方式 (ERankResetType)
};

#endif /* __WARLORD_GAMESVR_RES_ENTRY_RANK_DEFINE_H__ */
