/************************************************************************/
/* @file:	config_define.h                                             */
/* @brief:	配置相关定义                                                */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-22                                                  */
/* @last:	2017-06-22                                                  */
/*                                                                      */
/*                                                                      */
/* 包括配置文件路径和配置定义                                           */
/************************************************************************/

#ifndef __WARLORD_DEFINE_CONFIG_DEFINE_H__
#define __WARLORD_DEFINE_CONFIG_DEFINE_H__

#include "config_file_define.h"			// 配置文件路径
#include "config_entry_define.h"		// 配置属性项

//-----------------------------------------------------------------------------
// 资源重新加载类型
//-----------------------------------------------------------------------------
enum EConfigReloadType
{
	ECFRT_Null					= 0,
	ECFRT_All					= 1,	// 全部
	ECFRT_ConfigNetwork			= 2,	// 网络
	ECFRT_End,
};

#endif /* __WARLORD_DEFINE_CONFIG_DEFINE_H__ */
