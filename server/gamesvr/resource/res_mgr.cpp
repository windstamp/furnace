#include "resource/res_mgr.h"

//-----------------------------------------------------------------------------
// 初始化
//-----------------------------------------------------------------------------
bool ResMgr::Init()
{
	bool ret = true;

	// 加载静态属性列表
	ret = LoadAllEntryList();
	if (!ret) return false;

	return ret;
}

//-----------------------------------------------------------------------------
// 销毁
//-----------------------------------------------------------------------------
void ResMgr::Destroy()
{
	// do nothing
}

//-----------------------------------------------------------------------------
// 重新加载
// 
// @note 由于资源之间可能存在依赖关系，因此重新加载被依赖资源时，
//       会同时重新加载一次依赖于此资源的所有资源
//-----------------------------------------------------------------------------
bool ResMgr::Reload(const int _reload_type)
{
	bool ret = true;

	switch(_reload_type)
	{
	case EERT_All:
		ret = LoadAllEntryList();
		break;
	case EERT_Mission:
		ret = LoadMissionEntryList();
		break;
	case EERT_MissionCondition:
		ret = LoadMissionEntryList();
		if (ret) ret = LoadRankEntryList();
		break;
	case EERT_Rank:
		ret = LoadRankEntryList();
		break;
	case EERT_HeroBaseAtt:
		ret = LoadHeroBaseAttEntryList();
		break;
	case EERT_HeroBase:
		ret = LoadSkillEntryList();
		if (ret) ret = LoadPassiveSkillEntryList();
		if (ret) ret = LoadHeroBaseAttEntryList();
		if (ret) ret = LoadHeroBaseEntryList();
		break;
	case EERT_Hero:
		ret = LoadSkillEntryList();
		if (ret) ret = LoadPassiveSkillEntryList();
		if (ret) ret = LoadHeroBaseAttEntryList();
		if (ret) ret = LoadHeroBaseEntryList();
		if (ret) ret = LoadHeroEntryList();
		break;
	case EERT_HeroUpgrade:
		ret = LoadSkillEntryList();
		if (ret) ret = LoadPassiveSkillEntryList();
		if (ret) ret = LoadHeroBaseAttEntryList();
		if (ret) ret = LoadHeroBaseEntryList();
		if (ret) ret = LoadHeroEntryList();
		if (ret) ret = LoadHeroUpgradeEntryList();
		break;
	case EERT_Skill:
		ret = LoadSkillEntryList();
		break;
	case EERT_PassiveSkill:
		ret = LoadSkillEntryList();
		if (ret) ret = LoadPassiveSkillEntryList();
		break;
	case EERT_HeroGroup:
		ret = LoadHeroBaseAttEntryList();
		if (ret) ret = LoadHeroBaseEntryList();
		if (ret) ret = LoadHeroEntryList();
		if (ret) ret = LoadHeroGroupEntryList();
		break;
	case EERT_Scene:
		ret = LoadSkillEntryList();
		if (ret) ret = LoadPassiveSkillEntryList();
		if (ret) ret = LoadHeroBaseAttEntryList();
		if (ret) ret = LoadHeroBaseEntryList();
		if (ret) ret = LoadHeroEntryList();
		if (ret) ret = LoadHeroGroupEntryList();
		if (ret) ret = LoadSceneEntryList();
		break;
	default:
		break;
	}

	return ret;
}

//-----------------------------------------------------------------------------
// 加载静态属性列表
//-----------------------------------------------------------------------------
bool ResMgr::LoadAllEntryList()
{
	bool ret = true;

	// @note 注意各资源项之间的依赖关系
	//       这对资源加载顺序有严格要求

	// 任务完成条件
	ret = LoadMissionConditionEntryList();
	if (!ret) return false;

	// 任务
	ret = LoadMissionEntryList();
	if (!ret) return false;

	// 排行榜
	ret = LoadRankEntryList();
	if (!ret) return false;
	
	// 技能
	ret = LoadSkillEntryList();
	if (!ret) return false;
	
	// 被动技能
	ret = LoadPassiveSkillEntryList();
	if (!ret) return false;

	// 武将基础属性
	ret = LoadHeroBaseAttEntryList();
	if (!ret) return false;

	// 武将基本信息
	ret = LoadHeroBaseEntryList();
	if (!ret) return false;

	// 武将信息
	ret = LoadHeroEntryList();
	if (!ret) return false;
	
	// 武将升星
	ret = LoadHeroUpgradeEntryList();
	if (!ret) return false;

	// 英雄组信息
	ret = LoadHeroGroupEntryList();
	if (!ret) return false;
	
	// 战斗场景信息
	ret = LoadSceneEntryList();
	if (!ret) return false;
	
	return ret;
}
