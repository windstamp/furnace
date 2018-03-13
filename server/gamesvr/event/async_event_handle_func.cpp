#include "player/player_mgr.h"

#include "event/async_event_handle_func.h"

void player_mgr_handle_async_event_time_change (tagEventBase* _event_base)
{
	return sPlayerMgr->HandleAsyncEventTimeChange(_event_base);
}
