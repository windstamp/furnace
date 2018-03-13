/************************************************************************/
/* @file:	res_entry_hero_att_define.h                                 */
/* @brief:	武将属性静态资源项属性定义                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-03-28                                                  */
/* @last:	2017-06-15                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_RES_ENTRY_ENTITY_DEFINE_H__
#define __WARLORD_GAMESVR_RES_ENTRY_ENTITY_DEFINE_H__

#include "common.h"

//-------------------------------------------------------------------------------
// 属性
//-------------------------------------------------------------------------------
enum EHeroAtt
{
	EHA_Null		= -1,
	EHA_Start		= 0,

	EHA_AttStart		= EHA_Start,
	EHA_AttackPower		= EHA_AttStart + 0,		// 攻击力
	EHA_DefenceMelee	= EHA_AttStart + 1,		// 物理防御
	EHA_DefenceMagic	= EHA_AttStart + 2,		// 法术防御
	EHA_Hit				= EHA_AttStart + 3,		// 命中率
	EHA_Dodge			= EHA_AttStart + 4,		// 闪避率
	EHA_Crit			= EHA_AttStart + 5,		// 暴击率
	EHA_Decrit			= EHA_AttStart + 6,		// 韧性
	EHA_CritInc			= EHA_AttStart + 7,		// 暴击伤害加成
	EHA_CritDec			= EHA_AttStart + 8,		// 暴击伤害减免
	EHA_Block			= EHA_AttStart + 9,		// 格档
	EHA_Broken			= EHA_AttStart + 10,	// 破击
	EHA_MaxHp			= EHA_AttStart + 11,	// 生命值上限
	EHA_MaxRage			= EHA_AttStart + 12,	// 怒气值上限
	EHA_InitRage		= EHA_AttStart + 13,	// 怒气值上限
	EHA_DmgInc			= EHA_AttStart + 14,	// 伤害加成
	EHA_DmgDec			= EHA_AttStart + 15,	// 伤害减免
	EHA_HealInc			= EHA_AttStart + 16,	// 被治疗加成
	EHA_PctDmgInc		= EHA_AttStart + 17,	// 百分比伤害加成
	EHA_PctDmgDec		= EHA_AttStart + 18,	// 百分比伤害减免
	EHA_Speed			= EHA_AttStart + 19,	// 速度
	EHA_AttEnd			= EHA_AttStart + 20,
	EHA_CurStart		= EHA_AttEnd,
	EHA_CurHP			= EHA_CurStart + 0,		// 当前生命值
	EHA_CurRage			= EHA_CurStart + 1,		// 当前怒气值
	EHA_CurSpeed		= EHA_CurStart + 2,		// 当前速度
	EHA_CurEnd			= EHA_CurStart + 3,

	EHA_End				= EHA_CurEnd
};

//-------------------------------------------------------------------------------
// 状态类型
//-------------------------------------------------------------------------------
enum EHeroState
{
	EHS_Dead		= 0,	// 死亡
	EHS_Solid		= 1,	// 石化
	EHS_Freeze		= 2,	// 冻结
	EHS_Stun		= 3,	// 眩晕
	EHS_Curse		= 4,	// 诅咒

	EHS_End
};

//-------------------------------------------------------------------------------
// 属性静态表
//-------------------------------------------------------------------------------
struct MemHeroBaseAttEntry
{
	int64_t						id;
	std::map<int32_t, int32_t>	fight_att;		// <EHeroAtt, value>

	MemHeroBaseAttEntry()
	{
		id	= 0;
		
		fight_att.clear();
	}
};

#endif /* __WARLORD_GAMESVR_RES_ENTRY_ENTITY_DEFINE_H__ */
