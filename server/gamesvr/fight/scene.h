/************************************************************************/
/* @file:	scene.h                                                     */
/* @brief:	战斗场景类                                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-23                                                  */
/* @last:	2017-07-15                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_SCENE_H__
#define __WARLORD_GAMESVR_SCENE_H__

#include "common.h"

#include <boost/tuple/tuple.hpp>

#include "define/res_define.h"

#include "fight/fight_util_object.h"
#include "fight/round.h"

class MemEnterSceneInfo;

class Fightable;
class FightGroup;
class FightHero;

class Scene
{
public:
	//-------------------------------------------------------------------------
	// 构造函数和析构函数
	//-------------------------------------------------------------------------
	Scene();
	~Scene();
	
public:
	//-------------------------------------------------------------------------
	// 初始化和销毁
	//-------------------------------------------------------------------------
	bool							Init(MemEnterSceneInfo* _info);
	void							Destroy();
	
public:
	//-------------------------------------------------------------------------
	// 每帧更新
	//-------------------------------------------------------------------------
	void							Update();
		
public:
	//-------------------------------------------------------------------------
	// 回合制战斗
	// 构建下一回合
	// 每回合结束响应函数
	//-------------------------------------------------------------------------
	void							BuildNextRound(const int32_t _round);
	void							OnRoundFinish();
	
private:
	//-------------------------------------------------------------------------
	// 战斗结束响应函数
	//-------------------------------------------------------------------------
	void							OnBattleFinish();

public:
	//-------------------------------------------------------------------------
	// 成员变量的 get/set 函数
	//-------------------------------------------------------------------------
	inline	int64_t					get_id()					{ return id_; }	
	inline	int64_t					get_creator_id()			{ return creator_id_; }
	inline	int64_t					get_scene_entry_id()		{ return scene_entry_id_; }
	inline	int32_t					get_scene_entry_type()		{ return scene_entry_type_; }
	
	inline	bool					is_delete()					{ return is_delete_; }
	inline	ECamp					get_win_camp()				{ return win_camp_; }
	
	inline	const MemSceneEntry*	get_scene_entry()			{ return scene_entry_; }
	inline	MemEnterSceneInfo*		get_scene_info()			{ return scene_info_; }
	
	inline	FightGroup**			get_fight_group()			{ return fight_group_; }
	inline	FightGroup*				get_fight_group(const int32_t camp)			{ return fight_group_[camp]; }
	
	inline	int32_t					get_round_index()			{ return round_index_; }
	inline	Round*					get_round()					{ return round_; }

	
	std::list< boost::tuple<FightHero*, int64_t> >&		get_hero_skill_cd_list()		{ return hero_skill_cd_list_; }
	
private:
	//-------------------------------------------------------------------------
	// 成员变量
	//-------------------------------------------------------------------------
	int64_t					id_;
	int64_t					creator_id_;
	int64_t					scene_entry_id_;
	int32_t					scene_entry_type_;
	
	bool					is_delete_;
	ECamp					win_camp_;
	
	const MemSceneEntry*	scene_entry_;
	
	MemEnterSceneInfo*		scene_info_;
	
	FightGroup*				fight_group_[EC_End];	// 双方战斗阵容
	
	int32_t					round_index_;			// 当前第几个回合
	Round*					round_;
	
	std::list< boost::tuple<FightHero*, int64_t> >	hero_skill_cd_list_;		// 英雄技能CD列表	<FightHero*, timestamp>
};

#endif /* __WARLORD_GAMESVR_SCENE_H__ */
