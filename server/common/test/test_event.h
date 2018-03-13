/************************************************************************/
/* @file:	test_event.h                                                */
/* @brief:	事件相关测试集                                              */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-29                                                  */
/* @last:	2017-07-29                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_COMMON_TEST_EVENT_H__
#define __WARLORD_COMMON_TEST_EVENT_H__

#include "define/event_define.h"

//-----------------------------------------------------------------------------
// 测试异步事件枚举值
//-----------------------------------------------------------------------------
enum ETestAsycnEvent
{
	ETAE_Null			= 0,
	ETAE_Start			= 1,
	
	ETAE_AsyncTest		= ETAE_Start + 0,		// 测试事件
	
	ETAE_End,
};

//-----------------------------------------------------------------------------
// 测试同步事件枚举值
//-----------------------------------------------------------------------------
enum ETestSycnEvent
{
	ETSE_Null			= 0,
	ETSE_Start			= 1,
	
	ETSE_SyncTest		= ETSE_Start + 0,		// 测试事件
	
	ETSE_End,
};

//-----------------------------------------------------------------------------
// 异步测试具体事件
//-----------------------------------------------------------------------------
EVENT_BEGIN(AsyncTest, ETAE_AsyncTest)
	int32_t		value;
EVENT_END

//-----------------------------------------------------------------------------
// 同步测试具体事件
//-----------------------------------------------------------------------------
EVENT_BEGIN(SyncTest, ETSE_SyncTest)
	int32_t		value;
EVENT_END

void asycn_event_handle_test_func(tagEventBase* _event_base);
void sycn_event_handle_test_func(tagEventBase& _event_base);

void test_event();

#endif	/* __WARLORD_COMMON_TEST_EVENT_H__ */
