#include "resource/res_mgr.h"

//-----------------------------------------------------------------------------
// ���ؾ�̬�����б� - ����
//-----------------------------------------------------------------------------
bool ResMgr::LoadMissionEntryList()
{
	bool ret = true;

	// �������Լ�����
	// XmlLoader MissionEntryLoader;

	// ����ID�б�
	// std::list<LPCSTR> listId;
	// ret = MissionEntryLoader.Load(NULL, MISSION_ENTRY_FILE, listId);
	// if (!ret) return false;

	// ��ʼ��ÿ��������
	// std::list<LPCSTR>::iterator iter;

	// CHAR szToken[SHORT_STRING] = {'\0'};

	// for (iter = listId.begin(); iter != listId.end(); ++iter)
	// {
		// LPCSTR szMissionId = *iter;

		// int64_t n64MissionId = ToNumber(szMissionId);

		// MemMissionEntry entry;
		// entry.id	= n64MissionId;
		// entry.type	= ToNumber( MissionEntryLoader.Get("type", szMissionId, "0") );
		// entry.reset_type	= ToNumber( MissionEntryLoader.Get("reset_type", szMissionId, "0") );
		// entry.drop_id		= ToNumber( MissionEntryLoader.Get("drop_id", szMissionId, "0") );
		// entry.level_limit	= ToNumber( MissionEntryLoader.Get("level_limit", szMissionId, "0") );
		// entry.next_mission_id	= ToNumber( MissionEntryLoader.Get("next_mission_id", szMissionId, "0") );
		// mission_entry_map_[n64MissionId] = entry;
	// }

	return ret;
}

//-----------------------------------------------------------------------------
// ���ؾ�̬�����б� - �����������
//-----------------------------------------------------------------------------
bool ResMgr::LoadMissionConditionEntryList()
{
	bool ret = true;

	// ��������������Լ�����
	// XmlLoader MissionConditionEntryLoader;

	// ����ID�б�
	// std::list<LPCSTR> listId;
	// ret = MissionConditionEntryLoader.Load(NULL, MISSION_CONDITION_ENTRY_FILE, listId);
	// if (!ret) return false;

	// ��ʼ��ÿ�����������
	// std::list<LPCSTR>::iterator iter;

	// CHAR szToken[SHORT_STRING] = {'\0'};

	// for (iter = listId.begin(); iter != listId.end(); ++iter)
	// {
	//	LPCSTR szMissionConditionId = *iter;

	//	int64_t n64MissionConditionId = ToNumber(szMissionConditionId);

	//	MemMissionEntry entry;
	//	entry.id	= n64MissionConditionId;
	//	entry.type	= ToNumber( MissionEntryLoader.Get("event_type", szMissionConditionId, "0") );
	//	entry.reset_type	= ToNumber( MissionEntryLoader.Get("count", szMissionConditionId, "0") );
	//	entry.drop_id		= ToNumber( MissionEntryLoader.Get("param1", szMissionConditionId, "0") );
	//	entry.level_limit	= ToNumber( MissionEntryLoader.Get("param2", szMissionConditionId, "0") );
	//	entry.next_mission_id	= ToNumber( MissionEntryLoader.Get("param3", szMissionConditionId, "0") );
	//	entry.next_mission_id	= ToNumber( MissionEntryLoader.Get("param4", szMissionConditionId, "0") );
	//	mission_condition_entry_map_[n64MissionConditionId] = entry;
	//}

	return ret;
}
