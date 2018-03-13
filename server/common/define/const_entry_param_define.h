/************************************************************************/
/* @file:	const_entry_param_define.h                                  */
/* @brief:	������������                                                */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-21                                                  */
/* @last:	2017-06-21                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_DEFINE_CONST_ENTRY_PARAM_DEFINE_H__
#define __WARLORD_DEFINE_CONST_ENTRY_PARAM_DEFINE_H__

#include "common.h"

//-----------------------------------------------------------------------------
// ��������
//-----------------------------------------------------------------------------
struct MemConstParam
{
	struct MemConstParamGuild
	{
		MemConstParamGuild()
		{
			Init();
		}
		
		void Init()
		{
			bzero( this, sizeof(*this) );
		}
		
		int32_t		max_member_num;		// ����Ա����
	};
	
	struct MemConstParamPlayer
	{
		MemConstParamPlayer()
		{
			Init();
		}
		
		void Init()
		{
			bzero( this, sizeof(*this) );
		}
		
		int32_t		fight_hero_num;	// �����佫����
	};

	MemConstParam()
	{
		Init();
	}
	
	void Init()
	{
		guild.Init();
		player.Init();
	}

	struct MemConstParamGuild	guild;	// ����
	struct MemConstParamPlayer	player;	// ���
};

#endif /* __WARLORD_DEFINE_CONST_ENTRY_PARAM_DEFINE_H__ */
