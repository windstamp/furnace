/************************************************************************/
/* @file:	res_entry_skill_define.h                                    */
/* @brief:	战斗相关定义                                                */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-18                                                  */
/* @last:	2017-06-18                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_RES_ENTRY_SKILL_DEFINE_H__
#define __WARLORD_GAMESVR_RES_ENTRY_SKILL_DEFINE_H__

//-----------------------------------------------------------------------------
// 技能目标类型
//-----------------------------------------------------------------------------
enum ESkillTarget
{
	EST_Start				= 1,
	EST_Self				= 1,	// 对武将本身施放
	EST_Our					= 2,	// 我方
	EST_Opposize			= 3,	// 对方
	EST_OpposizeFrontRow	= 4,	// 前排
	EST_OpposizeRockRow		= 5,	// 中排
	EST_OpposizeBackRow		= 6,	// 后排
	EST_End,
};

//-----------------------------------------------------------------------------
// 效果类型
//-----------------------------------------------------------------------------
enum ESkillEffect
{
	ESE_Start					= 1,
	ESE_DamageMelee			= 1,	// 物理伤害
	ESE_DamageMagic			= 2,	// 法术伤害
	ESE_End,
};

//-----------------------------------------------------------------------------
// 被动技能条件类型
//-----------------------------------------------------------------------------
enum EPassiveSkillCondition
{
	EPSC_Start					= 1,
	EPSC_BeginRageInc			= 1,	// 开场增加怒气
	EPSC_BeginRageDec			= 2,	// 开场减少怒气
	EPSC_BeginSpeedInc			= 3,	// 开场增加攻速
	EPSC_BeginSpeedDec			= 4,	// 开场降低攻速
	EPSC_BeginDamageInc			= 5,	// 开场增加伤害
	EPSC_BeginDamageDec			= 6,	// 开场减少伤害
	EPSC_End,
};

//-----------------------------------------------------------------------------
// 静态资源配置表 - 技能
//-----------------------------------------------------------------------------
struct MemSkillEntry
{
	MemSkillEntry()
	{
		id			= 0;
		target_type		= 0;
		target_param	= 0;
		effect_type		= 0;
		effect_param	= 0;
	}

	int64_t			id;			// 类型ID
	int32_t			target_type;	// 目标类型 		(ESkillTarget)
	int32_t			target_param;	// 目标类型参数
	int32_t			effect_type;	// 效果类型 		(ESkillEffect)
	int32_t			effect_param;	// 效果类型参数
};

//-----------------------------------------------------------------------------
// 静态资源配置表 - 被动技能
//-----------------------------------------------------------------------------
struct MemPassiveSkillEntry
{
	MemPassiveSkillEntry()
	{
		id			= 0;
		condition_type	= 0;
		condition_param	= 0;
		skill_id		= 0;
		
		skill_entry		= NULL;
	}

	int64_t			id;				// 类型ID
	int32_t			condition_type;		// 被动技能条件类型 		(EPassiveSkillCondition)
	int32_t			condition_param;	// 被动技能条件类型参数
	int32_t			skill_id;			// 施放的技能
	
	const MemSkillEntry* skill_entry;
};

#endif /* __WARLORD_GAMESVR_RES_ENTRY_SKILL_DEFINE_H__ */
