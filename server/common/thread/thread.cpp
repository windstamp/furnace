// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "thread/thread.h"

//-----------------------------------------------------------------------------
// 构造函数和析构函数
//-----------------------------------------------------------------------------
Thread::Thread(Executor* _executor, ThreadMgr* _thread_mgr)
	: executor_(_executor), thread_mgr_(_thread_mgr),
	  tid_( (pthread_t)0 ), id_(0)
{
}

Thread::~Thread()
{
	SAFE_DEL(executor_);
}

//-----------------------------------------------------------------------------
// 执行和结束
//-----------------------------------------------------------------------------
void Thread::Stop()
{
	if (executor_)
		executor_->OnShutDown();
}

