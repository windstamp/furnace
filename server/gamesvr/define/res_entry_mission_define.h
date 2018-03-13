/************************************************************************/
/* @file:	res_entry_define.h                                          */
/* @brief:	任务静态资源项属性定义                                          */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-03-28                                                  */
/* @last:	2017-03-28                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_RES_ENTRY_MISSION_DEFINE_H__
#define __WARLORD_GAMESVR_RES_ENTRY_MISSION_DEFINE_H__

//-----------------------------------------------------------------------------
// 任务类型
//-----------------------------------------------------------------------------
enum EMissionType
{
	EMT_Null	= 0,
	EMT_Main	= 1,	// 主线任务
	EMT_Branch	= 2,	// 支线任务
	EMT_Daily	= 3,	// 每日任务
	EMT_End,
};

//-----------------------------------------------------------------------------
// 任务状态
//-----------------------------------------------------------------------------
enum EMissionStatus
{
	EMS_Null		= 0,	// 未接任务
	EMS_Actived		= 1,	// 已激活
	EMS_Taken		= 2,	// 已接任务，未完成
	EMS_Finished	= 3,	// 已完成，未交付
	EMS_Completed	= 4,	// 已交付
	EMS_End,
};

//-----------------------------------------------------------------------------
// 任务重置方式
//-----------------------------------------------------------------------------
enum EMissionResetType
{
	EMRT_Null	= 0,	// 
	EMRT_None	= 1,	// 不重置
	EMRT_Day	= 2,	// 每日重置
	EMRT_Auto	= 3,	// 领取奖励后自动重置
	EMRT_End,
};

//-----------------------------------------------------------------------------
// 任务完成条件类型 (事件)
// 
// @note
// 任务静态配置表里面的完成类型依赖于此枚举值。
// 一旦定义之后，就不能用任务变动，只允许往后不断增加新的完成事件类型
//-----------------------------------------------------------------------------
enum EMissionEvent
{
	EME_Null		= 0,	//
	EME_Master_Level	= 1,	// 主角等级改变
	EME_Hero_Level		= 2,	// 英雄等级改变
	EME_Equip_Level		= 3,	// 装备等级改变
};

//-----------------------------------------------------------------------------
// 任务完成条件静态配置属性
//-----------------------------------------------------------------------------
struct MemMissionConditionEntry
{
	int64_t	id;		// 静态ID
	int32_t	event_type;	// 完成事件类型 (EMissionEvent)
	int32_t	count;		// 事件需要完成的次数
	int32_t	param1;	// 参数1
	int32_t	param2;	// 参数2
	int32_t	param3;	// 参数3
	int32_t	param4;	// 参数4
};

//-----------------------------------------------------------------------------
// 任务静态配置属性
//-----------------------------------------------------------------------------
struct MemMissionEntry
{
	int64_t		id;			// 任务静态ID
	int32_t		type;			// 任务类型 (EMissionType)
	int32_t		reset_type;		// 重置方式 (EMissionResetType)
	int64_t		condition_id;	// 完成条件ID
	int32_t		level_limit;	// 玩家等级限制
	int32_t		drop_id;		// 奖励掉落池ID
	int64_t		next_mission_id;	// 后续任务ID

	MemMissionConditionEntry*	condition_entry;	// 完成条件 (关联其它静态配置表)
};

#endif /* __WARLORD_GAMESVR_RES_ENTRY_MISSION_DEFINE_H__ */
