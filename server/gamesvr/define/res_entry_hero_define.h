/************************************************************************/
/* @file:	res_entry_hero_define.h                                     */
/* @brief:	战斗实体静态资源项属性定义                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-03-28                                                  */
/* @last:	2017-07-12                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_RES_ENTRY_HERO_DEFINE_H__
#define __WARLORD_GAMESVR_RES_ENTRY_HERO_DEFINE_H__

#include "common.h"

//-----------------------------------------------------------------------------
// 英雄站位
//-----------------------------------------------------------------------------
enum EHeroPosition
{
	EHP_Start		= 1,
	EHP_FrontRow	= 1,	// 前排
	EHP_RockRow		= 2,	// 中排
	EHP_BackRow		= 3,	// 后排
	EHP_End,
};

//-----------------------------------------------------------------------------
// 英雄伤害类型
//-----------------------------------------------------------------------------
enum EHeroDamageType
{
	EHDT_Start		= 1,
	EHDT_Melee		= 1,	// 物理伤害
	EHDT_Magic		= 2,	// 法术伤害
	EHDT_End,
};

//-----------------------------------------------------------------------------
// 英雄品质
//-----------------------------------------------------------------------------
enum EHeroQuality
{
	EHQ_Start			=		0,
	EHQ_White			=		0,		// 白板
	EHQ_GreenOne		=		1,		// 绿色1星
	EHQ_GreenTwo		=		2,		// 绿色2星
	EHQ_GreenThree		=		3,		// 绿色3星
	EHQ_BlueOne			=		4,		// 蓝色1星
	EHQ_BlueTwo			=		5,		// 蓝色2星
	EHQ_BlueThree		=		6,		// 蓝色3星
	EHQ_PurpleOne		=		7,		// 紫色1星
	EHQ_PurpleTwo		=		8,		// 紫色2星
	EHQ_PurpleThree		=		9,		// 紫色3星
	EHQ_OrangeOne		=		10,		// 橙色1星
	EHQ_OrangeTwo		=		11,		// 橙色2星
	EHQ_OrangeThree		=		12,		// 橙色3星
	EHQ_RedOne			=		13,		// 红色1星
	EHQ_RedTwo			=		14,		// 红色2星
	EHQ_RedThree		=		15,		// 红色3星
	EHQ_GoldOne			=		16,		// 金色1星
	EHQ_GoldTwo			=		17,		// 金色2星
	EHQ_GoldThree		=		18,		// 金色3星
	EHQ_End,
};

//-----------------------------------------------------------------------------
// 英雄基本信息静态表
//-----------------------------------------------------------------------------
class MemHeroBaseAttEntry;
class MemSkillEntry;

struct MemHeroBaseEntry
{
	MemHeroBaseEntry()
	{
		id						= 0;
		position				= 0;
		damage_type				= 0;
		common_skill_id			= 0;
		profound_skill_id		= 0;
		
		base_att_entry			= NULL;
		common_skill_entry		= NULL;
		profound_skill_entry	= NULL;
	}

	int64_t						id;						// 类型ID
	int32_t						position;				// 站位 		(EHeroPosition)
	int32_t						damage_type;			// 伤害类型		(EHeroDamageType)
	int64_t						common_skill_id;		// 普攻技能
	int64_t						profound_skill_id;		// 奥义技能
	
	const MemHeroBaseAttEntry*	base_att_entry;
	const MemSkillEntry*		common_skill_entry;
	const MemSkillEntry*		profound_skill_entry;
};

//-----------------------------------------------------------------------------
// 英雄信息静态表
//-----------------------------------------------------------------------------
struct MemHeroEntry
{
	MemHeroEntry()
	{
		id			= 0;
		type_id		= 0;
		quality		= 0;
		
		fight_att.clear();
		
		passive_skill	= 0;
		
		base_entry	= NULL;
	}
	
	bool get_fight_att(std::map<int32_t, int32_t>& _fight_att) const
	{
		for (auto iter_1 = fight_att.begin();
			 iter_1 != fight_att.end();
			 ++iter_1)
		{
			auto iter_2 = _fight_att.find(iter_1->first);
			
			if ( iter_2 == _fight_att.end() )
			{
				_fight_att[iter_1->first] = iter_1->second;
			}
			else
			{
				iter_2->second += iter_1->second;
			}
		}
	
		if (base_entry && base_entry->base_att_entry)
		{
			for (auto iter_1 = base_entry->base_att_entry->fight_att.begin();
				 iter_1 != base_entry->base_att_entry->fight_att.end();
				 ++iter_1)
			{
				auto iter_2 = _fight_att.find(iter_1->first);
				
				if ( iter_2 == _fight_att.end() )
				{
					_fight_att[iter_1->first] = iter_1->second;
				}
				else
				{
					iter_2->second += iter_1->second;
				}
			}
		}
		
		return true;
	}	

	int64_t						id;			// ID
	int64_t						type_id;		// 类型ID
	int32_t						quality;		// EHeroQuality	
	std::map<int32_t, int32_t>	fight_att;			// <EHeroAtt, value>
	int32_t						passive_skill;	// 被动技能
	
	const MemHeroBaseEntry*		base_entry;	// 基本信息项
};

//-----------------------------------------------------------------------------
// 武将升星 - 静态表
//-----------------------------------------------------------------------------
struct MemHeroUpgradeEntry
{
	MemHeroUpgradeEntry()
	{
		id		= 0;
		src_id	= 0;
		dst_id	= 0;
		
		cost_hero.clear();
		cost_item.clear();
		
		src_entry	= NULL;
		dst_entry	= NULL;
	}

	int64_t						id;			// ID
	int64_t						src_id;		// 源武将ID
	int64_t						dst_id;		// 目标武将ID
	std::map<int64_t, int32_t>	cost_hero;	// 所需材料 - 武将
	std::map<int64_t, int32_t>	cost_item;	// 所需材料 - 道具	
	
	const MemHeroEntry*			src_entry;	// 源武将基本信息项	
	const MemHeroEntry*			dst_entry;	// 目标武将基本信息项
};

#endif /* __WARLORD_GAMESVR_RES_ENTRY_HERO_DEFINE_H__ */
