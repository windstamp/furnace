/************************************************************************/
/* @file:	util_kit_mgr.h                                              */
/* @brief:	gamesvr�����������                                         */
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
	// ���캯������������
	//-------------------------------------------------------------------------
	UtilKitMgr()	{}
	~UtilKitMgr()	{}

public:
	//-------------------------------------------------------------------------
	// ��ʼ��������
	//-------------------------------------------------------------------------
	bool	Init();
	void	Destroy();
	
public:
	//-------------------------------------------------------------------------
	// ÿ֡����
	//-------------------------------------------------------------------------
	void			Update();

public:
	//-------------------------------------------------------------------------
	// ��Ա������ get/set ����
	//-------------------------------------------------------------------------
	EventMgr*		get_event_mgr()		{ return event_mgr_; }
	TimeMgr*		get_time_mgr()		{ return time_mgr_; }
	
	IdGenerator*	get_id_generator(const int32_t _type);
	
public:
	//-------------------------------------------------------------------------
	// ��Ա����
	//-------------------------------------------------------------------------
	EventMgr*		event_mgr_;
	TimeMgr*		time_mgr_;
	
	IdGenerator*	id_generators_[EIT_End];
};

#define sUtilKitMgr	Singleton<UtilKitMgr>::Instance()

#endif	/* __WARLORD_GAMESVR_UTIL_KIT_H__ */
