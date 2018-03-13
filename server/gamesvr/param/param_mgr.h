/************************************************************************/
/* @file:	param_mgr.h                                                 */
/* @brief:	全服公共参数管理器                                          */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-28                                                  */
/* @last:	2017-07-28                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_PARAM_MGR_H__
#define __WARLORD_GAMESVR_PARAM_MGR_H__

#include "common.h"

#include "define/param_define.h"

class ParamMgr
{
	friend class Singleton<ParamMgr>;
	
private:
	//-------------------------------------------------------------------------
	// 构造函数和析构函数
	//-------------------------------------------------------------------------
	ParamMgr()		{}
	~ParamMgr()	{}

public:
	//-------------------------------------------------------------------------
	// 初始化和销毁
	//-------------------------------------------------------------------------
	bool			Init();
	void			Destroy();
	
public:
	//-------------------------------------------------------------------------
	// 成员获取函数
	//-------------------------------------------------------------------------
	int64_t			get_zone_id()				{ return param_info_.zone_id; }
	int64_t			get_group_id()				{ return param_info_.group_id; }
	int64_t			get_open_timestamp()		{ return param_info_.open_timestamp; }
	
	void			set_zone_id(const int64_t _zone_id)						{ param_info_.zone_id = _zone_id; }
	void			set_group_id(const int64_t _group_id)					{ param_info_.group_id = _group_id; }
	void			set_open_timestamp(const int64_t _open_timestamp)		{ param_info_.open_timestamp = _open_timestamp; }
	
private:
	//-------------------------------------------------------------------------
	// 成员变量
	//-------------------------------------------------------------------------
	MemParamInfo	param_info_;
};

#define sParamMgr	Singleton<ParamMgr>::Instance()

#endif	/* #ifndef __WARLORD_GAMESVR_PARAM_MGR_H__ */
