/************************************************************************/
/* @file:	res_entry_hero_att_define.h                                 */
/* @brief:	�佫���Ծ�̬��Դ�����Զ���                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-03-28                                                  */
/* @last:	2017-06-15                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_RES_ENTRY_ENTITY_DEFINE_H__
#define __WARLORD_GAMESVR_RES_ENTRY_ENTITY_DEFINE_H__

#include "common.h"

//-------------------------------------------------------------------------------
// ����
//-------------------------------------------------------------------------------
enum EHeroAtt
{
	EHA_Null		= -1,
	EHA_Start		= 0,

	EHA_AttStart		= EHA_Start,
	EHA_AttackPower		= EHA_AttStart + 0,		// ������
	EHA_DefenceMelee	= EHA_AttStart + 1,		// �������
	EHA_DefenceMagic	= EHA_AttStart + 2,		// ��������
	EHA_Hit				= EHA_AttStart + 3,		// ������
	EHA_Dodge			= EHA_AttStart + 4,		// ������
	EHA_Crit			= EHA_AttStart + 5,		// ������
	EHA_Decrit			= EHA_AttStart + 6,		// ����
	EHA_CritInc			= EHA_AttStart + 7,		// �����˺��ӳ�
	EHA_CritDec			= EHA_AttStart + 8,		// �����˺�����
	EHA_Block			= EHA_AttStart + 9,		// ��
	EHA_Broken			= EHA_AttStart + 10,	// �ƻ�
	EHA_MaxHp			= EHA_AttStart + 11,	// ����ֵ����
	EHA_MaxRage			= EHA_AttStart + 12,	// ŭ��ֵ����
	EHA_InitRage		= EHA_AttStart + 13,	// ŭ��ֵ����
	EHA_DmgInc			= EHA_AttStart + 14,	// �˺��ӳ�
	EHA_DmgDec			= EHA_AttStart + 15,	// �˺�����
	EHA_HealInc			= EHA_AttStart + 16,	// �����Ƽӳ�
	EHA_PctDmgInc		= EHA_AttStart + 17,	// �ٷֱ��˺��ӳ�
	EHA_PctDmgDec		= EHA_AttStart + 18,	// �ٷֱ��˺�����
	EHA_Speed			= EHA_AttStart + 19,	// �ٶ�
	EHA_AttEnd			= EHA_AttStart + 20,
	EHA_CurStart		= EHA_AttEnd,
	EHA_CurHP			= EHA_CurStart + 0,		// ��ǰ����ֵ
	EHA_CurRage			= EHA_CurStart + 1,		// ��ǰŭ��ֵ
	EHA_CurSpeed		= EHA_CurStart + 2,		// ��ǰ�ٶ�
	EHA_CurEnd			= EHA_CurStart + 3,

	EHA_End				= EHA_CurEnd
};

//-------------------------------------------------------------------------------
// ״̬����
//-------------------------------------------------------------------------------
enum EHeroState
{
	EHS_Dead		= 0,	// ����
	EHS_Solid		= 1,	// ʯ��
	EHS_Freeze		= 2,	// ����
	EHS_Stun		= 3,	// ѣ��
	EHS_Curse		= 4,	// ����

	EHS_End
};

//-------------------------------------------------------------------------------
// ���Ծ�̬��
//-------------------------------------------------------------------------------
struct MemHeroBaseAttEntry
{
	int64_t						id;
	std::map<int32_t, int32_t>	fight_att;		// <EHeroAtt, value>

	MemHeroBaseAttEntry()
	{
		id	= 0;
		
		fight_att.clear();
	}
};

#endif /* __WARLORD_GAMESVR_RES_ENTRY_ENTITY_DEFINE_H__ */
