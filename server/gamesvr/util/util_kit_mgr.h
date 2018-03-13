/************************************************************************/
/* @file:	util_kit_mgr.h                                              */
/* @brief:	gamesvr公共类管理器                                         */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-25                                                  */
/* @last:	2017-07-25                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_UTIL_KIT_H__
#define __WARLORD_GAMESVR_UTIL_KIT_H__

#include "common.h"

#include "define/id_generator_define.h"

class IdGenerator;

class UtilKitMgr
{
	friend class Singleton<UtilKitMgr>;
	
private:
	//-------------------------------------------------------------------------
	// 构造函数和析构函数
	//-------------------------------------------------------------------------
	UtilKitMgr()	{}
	~UtilKitMgr()	{}

public:
	//-------------------------------------------------------------------------
	// 初始化、销毁
	//-------------------------------------------------------------------------
	bool	Init();
	void	Destroy();
	
public:
	//-------------------------------------------------------------------------
	// 每帧更新
	//-------------------------------------------------------------------------
	void			Update();

public:
	//-------------------------------------------------------------------------
	// 成员变量的 get/set 函数
	//-------------------------------------------------------------------------
	EventMgr*		get_event_mgr()		{ return event_mgr_; }
	TimeMgr*		get_time_mgr()		{ return time_mgr_; }
	
	IdGenerator*	get_id_generator(const int32_t _type);
	
public:
	//-------------------------------------------------------------------------
	// 成员变量
	//-------------------------------------------------------------------------
	EventMgr*		event_mgr_;
	TimeMgr*		time_mgr_;
	
	IdGenerator*	id_generators_[EIT_End];
};

#define sUtilKitMgr	Singleton<UtilKitMgr>::Instance()

#endif	/* __WARLORD_GAMESVR_UTIL_KIT_H__ */
