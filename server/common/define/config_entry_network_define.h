/************************************************************************/
/* @file:	config_entry_network_define.h                               */
/* @brief:	网络配置参数定义                                            */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-22                                                  */
/* @last:	2017-06-22                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_DEFINE_CONFIG_ENTRY_NETWORK_DEFINE_H__
#define __WARLORD_DEFINE_CONFIG_ENTRY_NETWORK_DEFINE_H__

#include "common.h"

//-----------------------------------------------------------------------------
// 常量参数
//-----------------------------------------------------------------------------
struct MemConfigNetwork
{
	struct MemConfigNetworkDbsvr
	{
		MemConfigNetworkDbsvr()
		{
			Init();
		}
		
		void Init()
		{
			ip		= "";
			port	= 0;
		}
		
		std::string			ip;		// IP
		int32_t				port;	// Port
	};
	
	struct MemConfigNetworkGamesvr
	{
		MemConfigNetworkGamesvr()
		{
			Init();
		}
		
		void Init()
		{
			ip		= "";
			port	= 0;
		}
		
		std::string			ip;		// IP
		int32_t				port;	// Port
	};
	
	struct MemConfigNetworkLoginsvr
	{
		MemConfigNetworkLoginsvr()
		{
			Init();
		}
		
		void Init()
		{
			ip		= "";
			port	= 0;
		}
		
		std::string			ip;		// IP
		int32_t				port;	// Port
	};
	
	MemConfigNetwork()
	{
		Init();
	}
	
	void Init()
	{
		dbsvr.Init();
		gamesvr.Init();
		loginsvr.Init();
	}

	struct MemConfigNetworkDbsvr	dbsvr;		// dbsvr
	struct MemConfigNetworkGamesvr	gamesvr;	// gamesvr
	struct MemConfigNetworkLoginsvr	loginsvr;	// loginsvr
};

#endif /* __WARLORD_DEFINE_CONFIG_ENTRY_NETWORK_DEFINE_H__ */
