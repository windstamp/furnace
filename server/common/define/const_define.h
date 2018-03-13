/************************************************************************/
/* @file:	const_define.h                                              */
/* @brief:	������ض���                                                */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-21                                                  */
/* @last:	2017-06-21                                                  */
/*                                                                      */
/*                                                                      */
/* ���������ļ�·���ͳ�������                                           */
/************************************************************************/

#ifndef __WARLORD_DEFINE_CONST_DEFINE_H__
#define __WARLORD_DEFINE_CONST_DEFINE_H__

#include "const_file_define.h"		// ��Դ�ļ�·��
#include "const_entry_define.h"		// ��Դ������

//-----------------------------------------------------------------------------
// ��Դ���¼�������
//-----------------------------------------------------------------------------
enum EConstReloadType
{
	ECRT_Null				= 0,
	ECRT_All				= 1,	// ȫ��
	ECRT_ConstParam			= 2,	// ����
	ECRT_End,
};

#endif /* __WARLORD_DEFINE_CONST_DEFINE_H__ */
