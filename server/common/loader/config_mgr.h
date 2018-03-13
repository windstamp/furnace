/************************************************************************/
/* @file:	config_mgr.h                                                */
/* @brief:	配置管理器                                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-22                                                  */
/* @last:	2017-06-22                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_COMMON_LOADER_CONFIG_MGR_H__
#define __WARLORD_COMMON_LOADER_CONFIG_MGR_H__

#include "define/config_define.h"

#include "singleton.h"

class ConfigMgr : public Singleton<ConfigMgr>
{
	friend class Singleton<ConfigMgr>;
	
private:
	//-------------------------------------------------------------------------
	// 构造函数和析构函数
	//-------------------------------------------------------------------------
	ConfigMgr()		{}
	~ConfigMgr()	{}

public:
	//-------------------------------------------------------------------------
	// 初始化、销毁、重新加载
	//-------------------------------------------------------------------------
	bool	Init();
	void	Destroy();
	bool	Reload(const int _reload_type);

public:
	//-------------------------------------------------------------------------
	// 获得各网络配置参数
	//-------------------------------------------------------------------------
	inline const MemConfigNetwork&			GetConfigNetwork() const			{ return config_network; }
	
private:
	//-------------------------------------------------------------------------
	// 加载配置静态属性列表
	//-------------------------------------------------------------------------
	bool	LoadAllConfig();

	bool	LoadConfigNetwork();	// 网络

private:
	MemConfigNetwork			config_network;				// 配置 - 网络
};

#define sConfigMgr	Singleton<ConfigMgr>::Instance()

#endif /* __WARLORD_COMMON_LOADER_CONFIG_MGR_H__ */
