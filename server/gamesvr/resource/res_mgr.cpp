#include "resource/res_mgr.h"

//-----------------------------------------------------------------------------
// ��ʼ��
//-----------------------------------------------------------------------------
bool ResMgr::Init()
{
	bool ret = true;

	// ���ؾ�̬�����б�
	ret = LoadAllEntryList();
	if (!ret) return false;

	return ret;
}

//-----------------------------------------------------------------------------
// ����
//-----------------------------------------------------------------------------
void ResMgr::Destroy()
{
	// do nothing
}

//-----------------------------------------------------------------------------
// ���¼���
// 
// @note ������Դ֮����ܴ���������ϵ��������¼��ر�������Դʱ��
//       ��ͬʱ���¼���һ�������ڴ���Դ��������Դ
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
// ���ؾ�̬�����б�
//-----------------------------------------------------------------------------
bool ResMgr::LoadAllEntryList()
{
	bool ret = true;

	// @note ע�����Դ��֮���������ϵ
	//       �����Դ����˳�����ϸ�Ҫ��

	// �����������
	ret = LoadMissionConditionEntryList();
	if (!ret) return false;

	// ����
	ret = LoadMissionEntryList();
	if (!ret) return false;

	// ���а�
	ret = LoadRankEntryList();
	if (!ret) return false;
	
	// ����
	ret = LoadSkillEntryList();
	if (!ret) return false;
	
	// ��������
	ret = LoadPassiveSkillEntryList();
	if (!ret) return false;

	// �佫��������
	ret = LoadHeroBaseAttEntryList();
	if (!ret) return false;

	// �佫������Ϣ
	ret = LoadHeroBaseEntryList();
	if (!ret) return false;

	// �佫��Ϣ
	ret = LoadHeroEntryList();
	if (!ret) return false;
	
	// �佫����
	ret = LoadHeroUpgradeEntryList();
	if (!ret) return false;

	// Ӣ������Ϣ
	ret = LoadHeroGroupEntryList();
	if (!ret) return false;
	
	// ս��������Ϣ
	ret = LoadSceneEntryList();
	if (!ret) return false;
	
	return ret;
}
