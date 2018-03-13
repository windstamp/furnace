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

#ifndef __WARLORD_GAMESVR_FIGHT_DEFINE_H__
#define __WARLORD_GAMESVR_FIGHT_DEFINE_H__

#include "common.h"

//-----------------------------------------------------------------------------
// 阵容类型
//-----------------------------------------------------------------------------
enum ECamp
{
	EC_Null		= -1,
	EC_Start	= 0,
	EC_Attack	= 0,	// 进攻方
	EC_Defence	= 1,	// 防守方
	EC_End,
};

//-----------------------------------------------------------------------------
// 战斗场景类型
//-----------------------------------------------------------------------------
enum ESceneFightSource
{
	ESFS_Null			= 0,
	ESFS_Start			= 1,
	ESFS_Stage			= ESFS_Start + 1,	// 关卡
	ESFS_CoupleArena	= ESFS_Start + 2,	// 夫妻擂台
	ESFS_End,
};

#include "define/res_entry_scene_define.h"
#include "define/res_entry_skill_define.h"

#endif /* __WARLORD_GAMESVR_FIGHT_DEFINE_H__ */
