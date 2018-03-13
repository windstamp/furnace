// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "define/public_define.h"
#include "define/event_define.h"

#include "event/event_mgr.h"

//-----------------------------------------------------------------------------
// ���캯������������
//-----------------------------------------------------------------------------
EventMgr::EventMgr()
{
}

EventMgr::~EventMgr()
{
	// ɾ�����е��¼�
	while ( !async_event_list_.empty() )
	{
		tagEventBase* event_base = async_event_list_.front();
		
		SAFE_DEL(event_base);
		
		async_event_list_.pop_front();
	}
	
	// ɾ�����еĴ�����
	
}

//-----------------------------------------------------------------------------
// ��ʼ��������
//-----------------------------------------------------------------------------
bool EventMgr::Init()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
	
	// sync_event_handle_func func;
	
	// tagEventBase event_base;
	
	// func(event_base);
	
	return true;
}

void EventMgr::Destroy()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
	
	return;
}

//-----------------------------------------------------------------------------
//  ÿ֡����
//-----------------------------------------------------------------------------
void EventMgr::Update()
{
	UpdateAsyncEvent();
}

//-----------------------------------------------------------------------------
// ע���첽�¼�������
//-----------------------------------------------------------------------------
bool EventMgr::RegisterAsyncEventHandler(const int32_t _event_id, async_event_handle_func _event_handler)
{
	if (!_event_handler)
	{
		BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _event_handler.";
		
		return false;
	}
	
	auto iter = async_event_handlers_.find(_event_id);
	
	if ( iter == async_event_handlers_.end() )
	{
		std::list<async_event_handle_func> even_handlers;
		even_handlers.push_back(_event_handler);
		
		async_event_handlers_[_event_id] = even_handlers;
	}
	else
	{
		iter->second.push_back(_event_handler);
	}	
	
	return true;
}

//-----------------------------------------------------------------------------
// ע��ͬ���¼�������
//-----------------------------------------------------------------------------
bool EventMgr::RegisterSyncEventHandler(const int32_t _event_id, sync_event_handle_func _event_handler)
{
	if (!_event_handler)
	{
		BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _event_handler.";
		
		return false;
	}
	
	auto iter = sync_event_handlers_.find(_event_id);
	
	if ( iter == sync_event_handlers_.end() )
	{
		std::list<sync_event_handle_func> even_handlers;
		even_handlers.push_back(_event_handler);
		
		sync_event_handlers_[_event_id] = even_handlers;
	}
	else
	{
		iter->second.push_back(_event_handler);
	}	
	
	return true;
}

//-----------------------------------------------------------------------------
//  ����첽�¼�
//-----------------------------------------------------------------------------
bool EventMgr::AddAsyncEvent(tagEventBase* _event_base)
{
	if (!_event_base)
	{
		BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _event_base.";
		
		return false;
	}
	
	async_event_list_.push_back(_event_base);
	
	return true;
}

//-----------------------------------------------------------------------------
//  ÿ֡���� - �����첽�¼�
//-----------------------------------------------------------------------------
void EventMgr::UpdateAsyncEvent()
{
	if ( async_event_list_.empty() )
		return;
	
	tagEventBase* event_base = async_event_list_.front();
	if (!event_base)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer event_base";
		
		return;
	}
	
	auto map_iter = async_event_handlers_.find(event_base->id_);
	if ( map_iter == async_event_handlers_.end() )
	{
		SAFE_DEL(event_base);
		async_event_list_.pop_front();
		
		return;
	}
	
	for (auto list_iter = map_iter->second.begin();
		 list_iter != map_iter->second.end();
		 ++list_iter)
	{
		async_event_handle_func func = *list_iter;
		if (!func)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "Null pointer func";
			
			continue;
		}
		
		func(event_base);
	}
	
	SAFE_DEL(event_base);
	async_event_list_.pop_front();
	
	return;
}

//-----------------------------------------------------------------------------
//  ����ͬ���¼�
//-----------------------------------------------------------------------------
void EventMgr::SendSyncEvent(tagEventBase& _event_base)
{
	auto map_iter = sync_event_handlers_.find(_event_base.id_);
	if ( map_iter == sync_event_handlers_.end() )
		return;
	
	for (auto list_iter = map_iter->second.begin();
		 list_iter != map_iter->second.end();
		 ++list_iter)
	{
		sync_event_handle_func func = *list_iter;
		if (!func)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "Null pointer func";
			
			continue;
		}
		
		func(_event_base);
	}
	
	return;
}

//-----------------------------------------------------------------------------
// ��Ա������ get/set ����
//-----------------------------------------------------------------------------
