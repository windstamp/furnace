/************************************************************************/
/* @file:	const_define.h                                              */
/* @brief:	常量相关定义                                                */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-21                                                  */
/* @last:	2017-06-21                                                  */
/*                                                                      */
/*                                                                      */
/* 包括常量文件路径和常量定义                                           */
/************************************************************************/

#ifndef __WARLORD_DEFINE_CONST_DEFINE_H__
#define __WARLORD_DEFINE_CONST_DEFINE_H__

#include "const_file_define.h"		// 资源文件路径
#include "const_entry_define.h"		// 资源属性项

//-----------------------------------------------------------------------------
// 资源重新加载类型
//-----------------------------------------------------------------------------
enum EConstReloadType
{
	ECRT_Null				= 0,
	ECRT_All				= 1,	// 全部
	ECRT_ConstParam			= 2,	// 任务
	ECRT_End,
};

#endif /* __WARLORD_DEFINE_CONST_DEFINE_H__ */
