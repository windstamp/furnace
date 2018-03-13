/************************************************************************/
/* @file:	test_event.h                                                */
/* @brief:	�¼���ز��Լ�                                              */
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
// �����첽�¼�ö��ֵ
//-----------------------------------------------------------------------------
enum ETestAsycnEvent
{
	ETAE_Null			= 0,
	ETAE_Start			= 1,
	
	ETAE_AsyncTest		= ETAE_Start + 0,		// �����¼�
	
	ETAE_End,
};

//-----------------------------------------------------------------------------
// ����ͬ���¼�ö��ֵ
//-----------------------------------------------------------------------------
enum ETestSycnEvent
{
	ETSE_Null			= 0,
	ETSE_Start			= 1,
	
	ETSE_SyncTest		= ETSE_Start + 0,		// �����¼�
	
	ETSE_End,
};

//-----------------------------------------------------------------------------
// �첽���Ծ����¼�
//-----------------------------------------------------------------------------
EVENT_BEGIN(AsyncTest, ETAE_AsyncTest)
	int32_t		value;
EVENT_END

//-----------------------------------------------------------------------------
// ͬ�����Ծ����¼�
//-----------------------------------------------------------------------------
EVENT_BEGIN(SyncTest, ETSE_SyncTest)
	int32_t		value;
EVENT_END

void asycn_event_handle_test_func(tagEventBase* _event_base);
void sycn_event_handle_test_func(tagEventBase& _event_base);

void test_event();

#endif	/* __WARLORD_COMMON_TEST_EVENT_H__ */
