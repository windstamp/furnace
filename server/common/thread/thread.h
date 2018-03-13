/************************************************************************/
/* @file:	thread.h                                                    */
/* @brief:	线程对象                                                    */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-08-14                                                  */
/* @last:	2017-08-14                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_COMMON_THREAD_H__
#define __WARLORD_COMMON_THREAD_H__

#include "public_include.h"

#include "thread/executor.h"

class Thread
{
	friend class ThreadMgr;
	
public:
	//-------------------------------------------------------------------------
	// 构造函数和析构函数
	//-------------------------------------------------------------------------
	Thread(Executor* _executor, ThreadMgr* _thread_mgr);
	~Thread();

private:
	//-------------------------------------------------------------------------
	// 拷贝构造函数和赋值拷贝运算符
	//-------------------------------------------------------------------------
	Thread(const Thread&);
	Thread& operator=(const Thread&);
	
public:
	//-------------------------------------------------------------------------
	// 执行和停止
	//-------------------------------------------------------------------------
	void			Stop();
	
public:
	//-------------------------------------------------------------------------
	// 成员获取函数
	//-------------------------------------------------------------------------
	Executor*		get_executor()			{ return executor_; }
	ThreadMgr*		get_thread_mgr()		{ return thread_mgr_; }
	pthread_t		get_tid()				{ return tid_; }
	int64_t			get_id()				{ return id_; }
	
private:
	//-------------------------------------------------------------------------
	// 成员变量
	//-------------------------------------------------------------------------
	Executor*			executor_;		// 执行体
	ThreadMgr*			thread_mgr_;	// 线程管理器
	
	pthread_t			tid_;			// 线程ID
	
	int64_t				id_;			// 线程管理器分配的ID
};

#endif	/* __WARLORD_COMMON_THREAD_H__ */
