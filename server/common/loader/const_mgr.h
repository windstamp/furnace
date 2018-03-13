/************************************************************************/
/* @file:	const_mgr.h                                                 */
/* @brief:	常量管理器                                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-21                                                  */
/* @last:	2017-06-21                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_COMMON_LOADER_CONST_MGR_H__
#define __WARLORD_COMMON_LOADER_CONST_MGR_H__

#include "define/const_define.h"

#include "singleton.h"

class ConstMgr : public Singleton<ConstMgr>
{
	friend class Singleton<ConstMgr>;
	
private:
	//-------------------------------------------------------------------------
	// 构造函数和析构函数
	//-------------------------------------------------------------------------
	ConstMgr()	{}
	~ConstMgr()	{}

public:
	//-------------------------------------------------------------------------
	// 初始化、销毁、重新加载
	//-------------------------------------------------------------------------
	bool	Init();
	void	Destroy();
	bool	Reload(const int _reload_type);

public:
	//-------------------------------------------------------------------------
	// 获得各常量参数
	//-------------------------------------------------------------------------
	inline const MemConstParam&			GetConstParam() const			{ return const_param; }
	
private:
	//-------------------------------------------------------------------------
	// 加载静态属性列表
	//-------------------------------------------------------------------------
	bool	LoadAllConst();

	bool	LoadConstParam();	// 任务

private:
	MemConstParam			const_param;				// 常量参数
};

#define sConstMgr	Singleton<ConstMgr>::Instance()

#endif /* __WARLORD_COMMON_LOADER_CONST_MGR_H__ */
