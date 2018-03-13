// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "thread/thread_mgr.h"


//-----------------------------------------------------------------------------
// 构造函数和析构函数
//-----------------------------------------------------------------------------
ThreadMgr::ThreadMgr()
{
}

ThreadMgr::~ThreadMgr()
{
}

//-----------------------------------------------------------------------------
// 初始化、销毁
//-----------------------------------------------------------------------------
bool ThreadMgr::Init()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
	
	if (pthread_mutex_init(&lock_, NULL) != 0)
	{
		BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "pthread_mutex_init failed.";
		
		return false;
	}
	
	return true;
}

void ThreadMgr::Destroy()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
	
	return;
}

void ThreadMgr::ShutDown()
{
	BOOST_LOG_TRIVIAL(info) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "";
	
	return;
}

//-----------------------------------------------------------------------------
// 创建、停止等线程操作
//-----------------------------------------------------------------------------
int64_t ThreadMgr::CreateThread(Executor* _executor)
{
	if (!_executor)
		return 0;
	
	Thread* thread = new Thread(_executor, this);
	
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	
	int err = pthread_create(&tid, &attr, _executor->Run(), (void *)thread);
	if (err != 0)
	{
		BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "pthread_create failed.";
		
		SAFE_DEL(thread);
		
		return 0;
	}
}
