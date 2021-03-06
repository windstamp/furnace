﻿/************************************************************************/
/* @file:	player_mgr.h                                                */
/* @brief:	玩家管理器                                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-01                                                  */
/* @last:	2017-07-01                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_PLAYER_MGR_H__
#define __WARLORD_GAMESVR_PLAYER_MGR_H__

#include "common.h"

class Player;

class PlayerMgr
{
	friend class Singleton<PlayerMgr>;
	
private:
	//-------------------------------------------------------------------------
	// 构造函数和析构函数
	//-------------------------------------------------------------------------
	PlayerMgr()		{}
	~PlayerMgr()	{}

public:
	//-------------------------------------------------------------------------
	// 初始化
	//-------------------------------------------------------------------------
	bool			Init();
	void			Destroy();
	
public:
	//-------------------------------------------------------------------------
	// 每帧更新
	//-------------------------------------------------------------------------
	void			Update();

public:
	//-------------------------------------------------------------------------
	// 异步事件响应函数
	//-------------------------------------------------------------------------
	void			HandleAsyncEventTimeChange(const tagEventBase* _event);
	
public:
	//-------------------------------------------------------------------------
	// 成员获取函数
	//-------------------------------------------------------------------------
	int64_t							gen_serial()		{ return ++serial_ + ( (int64_t)1001 << 40 ); }
	int64_t							gen_hero_seiral()	{ return ++hero_serial_ + ( (int64_t)1001 << 40 ); }
	
	Player*							get_player_by_id(const int64_t _id);

private:
	//-------------------------------------------------------------------------
	// 成员变量
	//-------------------------------------------------------------------------
	int64_t							serial_;
	int64_t							hero_serial_;

	std::map<int64_t, Player*>		player_map_;
};

#define sPlayerMgr	Singleton<PlayerMgr>::Instance()

#endif /* __WARLORD_GAMESVR_PLAYER_MGR_H__ */
