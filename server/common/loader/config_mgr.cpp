#include "config_mgr.h"

//-----------------------------------------------------------------------------
// ��ʼ��
//-----------------------------------------------------------------------------
bool ConfigMgr::Init()
{
	bool ret = true;

	// ���ؾ�̬�����б�
	ret = LoadAllConfig();
	if (!ret) return false;
	
	return ret;
}

//-----------------------------------------------------------------------------
// ����
//-----------------------------------------------------------------------------
void ConfigMgr::Destroy()
{
	// do nothing
}

//-----------------------------------------------------------------------------
// ���¼���
//-----------------------------------------------------------------------------
bool ConfigMgr::Reload(const int _reload_type)
{
	bool ret = true;

	switch(_reload_type)
	{
	case ECFRT_All:
		ret = LoadAllConfig();
		break;
	case ECFRT_ConfigNetwork:
		ret = LoadConfigNetwork();
		break;
	default:
		break;
	}

	return ret;
}

//-----------------------------------------------------------------------------
// ���ؾ�̬�����б�
//-----------------------------------------------------------------------------
bool ConfigMgr::LoadAllConfig()
{
	bool ret = true;

	// ��������
	ret = LoadConfigNetwork();
	if (!ret) return false;

	return ret;
}
