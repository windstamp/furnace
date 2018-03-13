/************************************************************************/
/* @file:	res_entry_hero_define.h                                     */
/* @brief:	战斗实体静态资源项属性定义                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-02                                                  */
/* @last:	2017-07-15                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_RES_ENTRY_SCENE_DEFINE_H__
#define __WARLORD_GAMESVR_RES_ENTRY_SCENE_DEFINE_H__

#include "common.h"

class MemHeroEntry;

//-----------------------------------------------------------------------------
// 怪物组信息静态表
//-----------------------------------------------------------------------------
struct MemHeroGroupEntry
{
	int64_t					id;
	int64_t					hero_id_1;
	int64_t					hero_id_2;
	int64_t					hero_id_3;
	int64_t					hero_id_4;
	int64_t					hero_id_5;
	int64_t					hero_id_6;
	int32_t					pos_1;
	int32_t					pos_2;
	int32_t					pos_3;
	int32_t					pos_4;
	int32_t					pos_5;
	int32_t					pos_6;
	
	const MemHeroEntry*		hero_entry_1;
	const MemHeroEntry*		hero_entry_2;
	const MemHeroEntry*		hero_entry_3;
	const MemHeroEntry*		hero_entry_4;
	const MemHeroEntry*		hero_entry_5;
	const MemHeroEntry*		hero_entry_6;
	
	std::map<int32_t, const MemHeroEntry*>	hero_entrys;	// <pos, hero_entry>
};

//-----------------------------------------------------------------------------
// 战斗场景信息静态表
//-----------------------------------------------------------------------------
struct MemSceneEntry
{
	int64_t						id;					// 
	int32_t						type;				// ESceneFightSource
	int64_t						hero_group_id;		// 怪物组ID
	
	const MemHeroGroupEntry*	hero_group_entry;
};

#endif /* __WARLORD_GAMESVR_RES_ENTRY_SCENE_DEFINE_H__ */
