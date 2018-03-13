/************************************************************************/
/* @file:	res_mgr.h                                                   */
/* @brief:	��̬��Դ������                                              */
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
	// ���캯������������
	//-------------------------------------------------------------------------
	ResMgr()	{}
	~ResMgr()	{}

public:
	//-------------------------------------------------------------------------
	// ��ʼ�������١����¼���
	//-------------------------------------------------------------------------
	bool	Init();
	void	Destroy();
	bool	Reload(const int _reload_type);

public:
	//-------------------------------------------------------------------------
	// ��ø���Դ����������
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
	// ��ø���Դ������
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
	// ���ؾ�̬�����б�
	//-------------------------------------------------------------------------
	bool	LoadAllEntryList();

	bool	LoadMissionConditionEntryList();	// ����
	bool	LoadMissionEntryList();				// �����������

	bool	LoadRankEntryList();				// ���а�

	bool	LoadHeroBaseEntryList();			// �佫������Ϣ
	bool	LoadHeroBaseAttEntryList();			// �佫��������
	bool	LoadHeroEntryList();				// �佫��Ϣ
	bool	LoadHeroGroupEntryList();			// Ӣ����
	bool	LoadHeroUpgradeEntryList();			// �佫������Ϣ
	bool	LoadSceneEntryList();				// ս��������Ϣ
	
	bool	LoadSkillEntryList();				// ����
	bool	LoadPassiveSkillEntryList();		// ��������

private:
	std::map<int64_t, MemMissionEntry>			mission_entry_map_;					// ����̬��������
	std::map<int64_t, MemHeroUpgradeEntry>		mission_condition_entry_map_;		// �������������̬��������	

	std::map<int64_t, MemRankEntry>				rank_entry_map_;					// ���а�̬��������

	std::map<int64_t, MemHeroBaseEntry>			hero_base_entry_map_;				// �������Ծ�̬��������
	std::map<int64_t, MemHeroBaseAttEntry>		hero_base_att_entry_map_;			// �������Գɳ���̬��������
	std::map<int64_t, MemHeroEntry>				hero_entry_map_;					// Ӣ�۾�̬��������
	std::map<int64_t, MemHeroGroupEntry>		hero_group_entry_map_;				// Ӣ���龲̬��������
	std::map<int64_t, MemHeroUpgradeEntry>		hero_upgrade_entry_map_;			// Ӣ��������������
	std::map<int64_t, MemSceneEntry>			scene_entry_map_;					// ս��������̬��������
	
	std::map<int64_t, MemSkillEntry>			skill_entry_map_;					// ���ܾ�̬��������
	std::map<int64_t, MemPassiveSkillEntry>		passive_skill_entry_map_;			// �������ܾ�̬��������
};

#define sResMgr	Singleton<ResMgr>::Instance()

#endif /* __WARLORD_GAMESVR_RES_MGR_H__ */
