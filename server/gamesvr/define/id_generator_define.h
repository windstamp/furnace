/************************************************************************/
/* @file:	id_generator_define.h                                       */
/* @brief:	ID类型定义                                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-28                                                  */
/* @last:	2017-07-28                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_ID_GENERATOR_DEFINE_H__
#define __WARLORD_GAMESVR_ID_GENERATOR_DEFINE_H__

//-----------------------------------------------------------------------------
// ID类型
//-----------------------------------------------------------------------------
enum EIdType
{
	EIT_Null	= -1,
	EIT_Start	= 0,
	EIT_Player	= EIT_Start + 0,	// 玩家ID
	EIT_Hero	= EIT_Start + 1,	// 英雄ID
	EIT_Item	= EIT_Start + 2,	// 道具ID
	
	EIT_End,
};

#endif	/* #ifndef __WARLORD_GAMESVR_ID_GENERATOR_DEFINE_H__ */
