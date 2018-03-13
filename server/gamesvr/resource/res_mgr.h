/************************************************************************/
/* @file:	res_mgr.h                                                   */
/* @brief:	静态资源管理器                                              */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-03-28                                                  */
/* @last:	2017-06-16                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_RES_MGR_H__
#define __WARLORD_GAMESVR_RES_MGR_H__

#include "common.h"

#include "define/res_define.h"

class ResMgr : public Singleton<ResMgr>
{
	friend class Singleton<ResMgr>;
	
private:
	//-------------------------------------------------------------------------
	// 构造函数和析构函数
	//-------------------------------------------------------------------------
	ResMgr()	{}
	~ResMgr()	{}

public:
	//-------------------------------------------------------------------------
	// 初始化、销毁、重新加载
	//-------------------------------------------------------------------------
	bool	Init();
	void	Destroy();
	bool	Reload(const int _reload_type);

public:
	//-------------------------------------------------------------------------
	// 获得各资源项属性容器
	//-------------------------------------------------------------------------
	inline std::map<int64_t, MemMissionEntry>&			GetMissionEntryList()			{ return mission_entry_map_; }
	inline std::map<int64_t, MemHeroUpgradeEntry>&	GetMissionConditionEntryList()	{ return mission_condition_entry_map_; }

	inline std::map<int64_t, MemRankEntry>&				GetRankEntryList()				{ return rank_entry_map_; }

	inline std::map<int64_t, MemHeroBaseEntry>&			GetHeroBaseEntryList()			{ return hero_base_entry_map_; }
	inline std::map<int64_t, MemHeroBaseAttEntry>&		GetHeroBaseAttEntryList()		{ return hero_base_att_entry_map_; }
	inline std::map<int64_t, MemHeroEntry>&				GetHeroEntryList()				{ return hero_entry_map_; }
	inline std::map<int64_t, MemHeroGroupEntry>&		GetHeroGroupEntryList()			{ return hero_group_entry_map_; }
	inline std::map<int64_t, MemHeroUpgradeEntry>&		GetHeroUpgradeEntryList()		{ return hero_upgrade_entry_map_; }
	inline std::map<int64_t, MemSceneEntry>&			GetSceneEntryList()				{ return scene_entry_map_; }
	
	inline std::map<int64_t, MemSkillEntry>&			GetSkillEntryList()				{ return skill_entry_map_; }
	inline std::map<int64_t, MemPassiveSkillEntry>&		GetPassiveSkillEntryList()		{ return passive_skill_entry_map_; }

public:
	//-------------------------------------------------------------------------
	// 获得各资源项属性
	//-------------------------------------------------------------------------
	const MemHeroBaseAttEntry*		GetHeroBaseAttEntry(const int64_t id) const;
	const MemHeroBaseEntry*			GetHeroBaseEntry(const int64_t id) const;
	const MemHeroEntry*				GetHeroEntry(const int64_t id) const;
	const MemHeroGroupEntry*		GetHeroGroupEntry(const int64_t id) const;
	const MemSceneEntry*			GetSceneEntry(const int64_t id) const;
	
	const MemSkillEntry*			GetSkillEntry(const int64_t id) const;
	const MemPassiveSkillEntry*		GetPassiveSkillEntry(const int64_t id) const;
	
private:
	//-------------------------------------------------------------------------
	// 加载静态属性列表
	//-------------------------------------------------------------------------
	bool	LoadAllEntryList();

	bool	LoadMissionConditionEntryList();	// 任务
	bool	LoadMissionEntryList();				// 任务完成条件

	bool	LoadRankEntryList();				// 排行榜

	bool	LoadHeroBaseEntryList();			// 武将基本信息
	bool	LoadHeroBaseAttEntryList();			// 武将基础属性
	bool	LoadHeroEntryList();				// 武将信息
	bool	LoadHeroGroupEntryList();			// 英雄组
	bool	LoadHeroUpgradeEntryList();			// 武将升星信息
	bool	LoadSceneEntryList();				// 战斗场景信息
	
	bool	LoadSkillEntryList();				// 技能
	bool	LoadPassiveSkillEntryList();		// 被动技能

private:
	std::map<int64_t, MemMissionEntry>			mission_entry_map_;					// 任务静态属性容器
	std::map<int64_t, MemHeroUpgradeEntry>		mission_condition_entry_map_;		// 任务完成条件静态属性容器	

	std::map<int64_t, MemRankEntry>				rank_entry_map_;					// 排行榜静态属性容器

	std::map<int64_t, MemHeroBaseEntry>			hero_base_entry_map_;				// 基础属性静态属性容器
	std::map<int64_t, MemHeroBaseAttEntry>		hero_base_att_entry_map_;			// 基础属性成长静态属性容器
	std::map<int64_t, MemHeroEntry>				hero_entry_map_;					// 英雄静态属性容器
	std::map<int64_t, MemHeroGroupEntry>		hero_group_entry_map_;				// 英雄组静态属性容器
	std::map<int64_t, MemHeroUpgradeEntry>		hero_upgrade_entry_map_;			// 英雄升星属性容器
	std::map<int64_t, MemSceneEntry>			scene_entry_map_;					// 战斗场景静态属性容器
	
	std::map<int64_t, MemSkillEntry>			skill_entry_map_;					// 技能静态属性容器
	std::map<int64_t, MemPassiveSkillEntry>		passive_skill_entry_map_;			// 被动技能静态属性容器
};

#define sResMgr	Singleton<ResMgr>::Instance()

#endif /* __WARLORD_GAMESVR_RES_MGR_H__ */
