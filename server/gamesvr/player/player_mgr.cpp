// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "define/server_event_define.h"

#include "event/async_event_handle_func.h"
#include "object/object_pool_mgr.h"
#include "player/player.h"
#include "util/util_kit_mgr.h"

#include "player/player_mgr.h"

//-----------------------------------------------------------------------------
// 初始化、销毁
//-----------------------------------------------------------------------------
bool PlayerMgr::Init()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
		
	EventMgr* event_mgr = sUtilKitMgr->get_event_mgr();
	if (!event_mgr)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer event_mgr";
		
		return false;
	}
	
	// 注册事件响应函数
	event_mgr->RegisterAsyncEventHandler(ESAE_TimeChange, player_mgr_handle_async_event_time_change);
	
	serial_ = 0;
	hero_serial_ = 0;
	
	for (int i = 0; i < 10; ++i)
	{
		++serial_;
	
		Player* player = sObjectPoolMgr->object_pool_player.construct();
		if (!player)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "Object pool construct failed for player";
			
			continue;
		}
		
		int64_t player_id = gen_serial();
		player->Init(player_id);
		
		player_map_[player_id] = player;
	}
	
	return true;
}

void PlayerMgr::Destroy()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
	
	std::map<int64_t, Player*>::iterator iter;
	std::map<int64_t, Player*>::iterator iter_begin	= player_map_.begin();
	std::map<int64_t, Player*>::iterator iter_end	= player_map_.end();
	
	for (iter = iter_begin; iter != iter_end; ++iter)
	{
		iter->second->Destroy();
		
		sObjectPoolMgr->object_pool_player.destroy(iter->second);
	}
	
	return;
}

//-----------------------------------------------------------------------------
//  每帧更新
//-----------------------------------------------------------------------------
void PlayerMgr::Update()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "online number: " << player_map_.size();
	
	std::map<int64_t, Player*>::iterator iter;
	std::map<int64_t, Player*>::iterator iter_begin	= player_map_.begin();
	std::map<int64_t, Player*>::iterator iter_end	= player_map_.end();

	for (iter = iter_begin; iter != iter_end; ++iter)
	{
		iter->second->Update();
	}
	
	return;
}

//-----------------------------------------------------------------------------
//  每帧更新
//-----------------------------------------------------------------------------
void PlayerMgr::HandleAsyncEventTimeChange(const tagEventBase* _event)
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
	
	if (!_event)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer _event.";
		
	}
	
	const tagEventTimeChange* event = (const tagEventTimeChange*)_event;
	
	if (!event)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "Null pointer event.";
		
	}
	
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "period = " << event->period << ", misc = " << event->misc;
	
	return;
}

//-----------------------------------------------------------------------------
// 成员获取函数
//-----------------------------------------------------------------------------
Player* PlayerMgr::get_player_by_id(const int64_t _id)
{
	auto iter = player_map_.find(_id);
	
	if ( iter != player_map_.end() )
		return iter->second;
	
	return NULL;
}
