/************************************************************************/
/* @file:	fight_util_object.h                                         */
/* @brief:	战斗需要的一些类定义                                        */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-24                                                  */
/* @last:	2017-07-10                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_FIGHT_UTIL_OBJECT_H__
#define __WARLORD_GAMESVR_FIGHT_UTIL_OBJECT_H__

#include "common.h"
#include "define/fight_define.h"
#include "define/res_define.h"

//-----------------------------------------------------------------------------
// 战斗英雄基础数据
//-----------------------------------------------------------------------------
struct MemFightHero
{
	MemFightHero();
	
	MemFightHero(const MemFightHero* rhs);
	
	MemFightHero& operator=(const MemFightHero* rhs);
	
	bool Init(const int64_t _hero_id, const int64_t _hero_type_id, const int32_t _level, const int32_t _pos, const int64_t _owner_id);
	
	int64_t						hero_id;		// 英雄ID
	int64_t						hero_type_id;	// 英雄类型ID
	int32_t						level;			// 英雄等级
	int32_t						pos;			// 位置
	int64_t						owner_id;		// 玩家ID
	
	std::map<int32_t, int32_t>	fight_att_map;		// <EHeroAtt, value>
	
	const MemHeroEntry*			hero_entry;
};

//-----------------------------------------------------------------------------
// 战斗阵容基础数据
//-----------------------------------------------------------------------------
struct MemFightGroup
{
	MemFightGroup();
	~MemFightGroup();
	
	MemFightGroup(const MemFightGroup* rhs);
	
	MemFightGroup& operator=(const MemFightGroup* rhs);
	
	bool Init();
	
	int64_t						param1;	// ID类型参数
	int32_t						param2;	// 参数1
	int32_t						param3;	// 参数2
	
	std::vector<MemFightHero*>	fight_hero_vec;	// 战斗英雄列表
};

//-----------------------------------------------------------------------------
// 各个战斗场景相关的杂项信息
//-----------------------------------------------------------------------------
struct MemSceneMiscInfo
{
	MemSceneMiscInfo();
	
	void Init();
	
	union
	{
		// 关卡
		struct
		{
			bool		pvp;
			int64_t		stage_id;
			int64_t		attack_player_id;
		} stage;
		
		// 夫妻擂台
		struct
		{
			bool	pvp;
			int64_t	attack_couple_id;
			int64_t attack_player_id_1;
			int64_t attack_player_id_2;
			int64_t defence_couple_id;
			int64_t defence_player_id_1;
			int64_t defence_player_id_2;
		} couple_arena;
	};
};

//-----------------------------------------------------------------------------
// 进入战斗场景的数据结构
//-----------------------------------------------------------------------------
struct MemEnterSceneInfo
{
	MemEnterSceneInfo();
	~MemEnterSceneInfo();
	
	void Init();
	
	int64_t				serial;					// 战斗场景动态ID
	int64_t				creator_id;				// 战斗发起者ID
	int64_t				scene_entry_id;			// 战斗场景静态ID
	int32_t				scene_entry_type;		// 战斗场景类型 (ESceneFightSource)
	
	MemFightGroup*		fight_group[EC_End];	// 战斗双方阵容
	
	MemSceneMiscInfo	misc_info;				// 各个战斗场景相关的杂项信息
};

#endif /* __WARLORD_GAMESVR_FIGHT_UTIL_OBJECT_H__ */
