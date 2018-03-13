#include "const_mgr.h"

//-----------------------------------------------------------------------------
// ��ʼ��
//-----------------------------------------------------------------------------
bool ConstMgr::Init()
{
	bool ret = true;

	// ���ؾ�̬�����б�
	ret = LoadAllConst();
	if (!ret) return false;

	return ret;
}

//-----------------------------------------------------------------------------
// ����
//-----------------------------------------------------------------------------
void ConstMgr::Destroy()
{
	// do nothing
}

//-----------------------------------------------------------------------------
// ���¼���
//-----------------------------------------------------------------------------
bool ConstMgr::Reload(const int _reload_type)
{
	bool ret = true;

	switch(_reload_type)
	{
	case ECRT_All:
		ret = LoadAllConst();
		break;
	case ECRT_ConstParam:
		ret = LoadConstParam();
		break;
	default:
		break;
	}

	return ret;
}

//-----------------------------------------------------------------------------
// ���ؾ�̬�����б�
//-----------------------------------------------------------------------------
bool ConstMgr::LoadAllConst()
{
	bool ret = true;

	// ��������
	ret = LoadConstParam();
	if (!ret) return false;

	return ret;
}
