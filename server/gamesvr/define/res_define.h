/************************************************************************/
/* @file:	res_define.h                                                */
/* @brief:	资源相关定义                                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-03-28                                                  */
/* @last:	2017-03-28                                                  */
/*                                                                      */
/*                                                                      */
/* 包括静态资源路径和静态资源属性定义                                         */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_RES_DEFINE_H__
#define __WARLORD_GAMESVR_RES_DEFINE_H__

#include "res_file_define.h"		// 资源文件路径
#include "res_entry_define.h"		// 资源属性项

//-----------------------------------------------------------------------------
// 资源重新加载类型
//-----------------------------------------------------------------------------
enum EEntryReloadType
{
	EERT_Null				= 0,
	EERT_All				= 1,	// 全部
	EERT_Mission			= 2,	// 任务
	EERT_MissionCondition	= 3,	// 任务完成条件
	EERT_Rank				= 4,	// 排行榜
	EERT_HeroBase			= 5,	// 武将基本属性信息
	EERT_HeroBaseAtt		= 6,	// 武将基本信息
	EERT_Hero				= 7,	// 武将信息
	EERT_HeroUpgrade		= 8,	// 武将升星
	EERT_Skill				= 9,	// 技能
	EERT_PassiveSkill		= 10,	// 被动技能
	EERT_HeroGroup			= 11,	// 怪物组
	EERT_Scene				= 12,	// 战斗场景
	EERT_End,
};

#endif /* __WARLORD_GAMESVR_RES_DEFINE_H__ */
