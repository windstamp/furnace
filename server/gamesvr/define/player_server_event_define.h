/************************************************************************/
/* @file:	player_event_define.h                                       */
/* @brief:	����¼�����                                            */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-27                                                  */
/* @last:	2017-07-27                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_PLAYER_EVENT_DEFINE_H__
#define __WARLORD_GAMESVR_PLAYER_EVENT_DEFINE_H__

#include "common.h"

//-----------------------------------------------------------------------------
// ����¼�ö��ֵ
//-----------------------------------------------------------------------------
enum EPlayerEvent
{
	EPE_Null			= 0,
	EPE_Start			= 1,
	
	EPE_MasterLevelUp	= EPE_Start + 0,		// ��������
	EPE_HeroLevelUp		= EPE_Start + 1,		// Ӣ������
	
	EPE_End,
};

//-----------------------------------------------------------------------------
// ��Ҿ����¼�
//-----------------------------------------------------------------------------
EVENT_BEGIN(MasterLevelUp, EPE_MasterLevelUp)
	int64_t		player_id;
	int32_t		pre_level;
	int32_t		cur_level;
EVENT_END

EVENT_BEGIN(HeroLevelUp, EPE_HeroLevelUp)
	int64_t		player_id;
	int32_t		pre_level;
	int32_t		cur_level;
EVENT_END

#endif /* __WARLORD_GAMESVR_PLAYER_EVENT_DEFINE_H__ */
