#include "const_mgr.h"

//-----------------------------------------------------------------------------
// 初始化
//-----------------------------------------------------------------------------
bool ConstMgr::Init()
{
	bool ret = true;

	// 加载静态属性列表
	ret = LoadAllConst();
	if (!ret) return false;

	return ret;
}

//-----------------------------------------------------------------------------
// 销毁
//-----------------------------------------------------------------------------
void ConstMgr::Destroy()
{
	// do nothing
}

//-----------------------------------------------------------------------------
// 重新加载
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
// 加载静态属性列表
//-----------------------------------------------------------------------------
bool ConstMgr::LoadAllConst()
{
	bool ret = true;

	// 常量参数
	ret = LoadConstParam();
	if (!ret) return false;

	return ret;
}
