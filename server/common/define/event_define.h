/************************************************************************/
/* @file:	event_define.h                                              */
/* @brief:	�¼�����                                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-27                                                  */
/* @last:	2017-07-27                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_COMMON_EVENT_DEFINE_H__
#define __WARLORD_COMMON_EVENT_DEFINE_H__

//-----------------------------------------------------------------------------
// �¼�����
//-----------------------------------------------------------------------------
struct tagEventBase
{
public:
	tagEventBase(int32_t _id) : id_(_id)	{}
	~tagEventBase()	{}
	
public:
	int32_t		id_;	// �¼�ID
};

// ͬ���¼�������
typedef	void (*sync_event_handle_func)(tagEventBase& _event_base);

// �첽�¼�������
typedef	void (*async_event_handle_func)(tagEventBase* _event_base);

//-----------------------------------------------------------------------------
// �����¼��ĺ�
//-----------------------------------------------------------------------------
#ifndef EVENT_BEGIN

#define	EVENT_BEGIN(name, id)					\
struct tagEvent##name : public tagEventBase		\
{												\
public:										\
	tagEvent##name() : tagEventBase(id)	{}		\
	~tagEvent##name()	{}						\
public:
#define	EVENT_END	};

#endif	/* #ifndef EVENT_BEGIN */

#endif /* __WARLORD_COMMON_EVENT_DEFINE_H__ */
