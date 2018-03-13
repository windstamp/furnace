#include "config_mgr.h"

//-----------------------------------------------------------------------------
// 初始化
//-----------------------------------------------------------------------------
bool ConfigMgr::Init()
{
	bool ret = true;

	// 加载静态属性列表
	ret = LoadAllConfig();
	if (!ret) return false;
	
	return ret;
}

//-----------------------------------------------------------------------------
// 销毁
//-----------------------------------------------------------------------------
void ConfigMgr::Destroy()
{
	// do nothing
}

//-----------------------------------------------------------------------------
// 重新加载
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
// 加载静态属性列表
//-----------------------------------------------------------------------------
bool ConfigMgr::LoadAllConfig()
{
	bool ret = true;

	// 常量参数
	ret = LoadConfigNetwork();
	if (!ret) return false;

	return ret;
}
