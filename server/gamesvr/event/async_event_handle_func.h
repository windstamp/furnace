/************************************************************************/
/* @file:	async_event_handle_func.h                                   */
/* @brief:	异步事件处理函数                                            */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-29                                                  */
/* @last:	2017-07-29                                                  */
/*                                                                      */
/* 异步事件辅助处理函数 - 只是为了语法能通过编译, 最终转发给各管理器    */
/*                                                                      */
/************************************************************************/

#include "common.h"

#ifndef __WARLORD_GAMESVR_ASYNC_EVENT_HANDLE_FUNC_H__
#define __WARLORD_GAMESVR_ASYNC_EVENT_HANDLE_FUNC_H__

void player_mgr_handle_async_event_time_change (tagEventBase* _event_base);

#endif	/* #ifndef __WARLORD_GAMESVR_ASYNC_EVENT_HANDLE_FUNC_H__ */
