/************************************************************************/
/* @file:	res_define.h                                                */
/* @brief:	��Դ��ض���                                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-03-28                                                  */
/* @last:	2017-03-28                                                  */
/*                                                                      */
/*                                                                      */
/* ������̬��Դ·���;�̬��Դ���Զ���                                         */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_RES_DEFINE_H__
#define __WARLORD_GAMESVR_RES_DEFINE_H__

#include "res_file_define.h"		// ��Դ�ļ�·��
#include "res_entry_define.h"		// ��Դ������

//-----------------------------------------------------------------------------
// ��Դ���¼�������
//-----------------------------------------------------------------------------
enum EEntryReloadType
{
	EERT_Null				= 0,
	EERT_All				= 1,	// ȫ��
	EERT_Mission			= 2,	// ����
	EERT_MissionCondition	= 3,	// �����������
	EERT_Rank				= 4,	// ���а�
	EERT_HeroBase			= 5,	// �佫����������Ϣ
	EERT_HeroBaseAtt		= 6,	// �佫������Ϣ
	EERT_Hero				= 7,	// �佫��Ϣ
	EERT_HeroUpgrade		= 8,	// �佫����
	EERT_Skill				= 9,	// ����
	EERT_PassiveSkill		= 10,	// ��������
	EERT_HeroGroup			= 11,	// ������
	EERT_Scene				= 12,	// ս������
	EERT_End,
};

#endif /* __WARLORD_GAMESVR_RES_DEFINE_H__ */
