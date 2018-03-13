/*
 * =====================================================================================
 *
 *       Filename:  singleton.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/29/2015 04:06:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __SINGLETON_H__
#define __SINGLETON_H__ 1

#include <stdlib.h>
#include <stdio.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

template<typename T>
class Singleton
{
 protected:
  Singleton() {}
  ~Singleton() {}
  
 public:
  static T* Instance()
  {
	  // printf("filename: %s\n", __FILE__);
	  
	  struct flock fl;
	  int fd;
	  
	  fl.l_type = F_WRLCK;
	  fl.l_whence = SEEK_SET;
	  fl.l_start = 0;
	  fl.l_len = 0;
	  fl.l_pid = getpid();
	  
	  if ( ( fd = open(__FILE__, O_WRONLY) ) == -1 )
	  {
		  perror("open() failed.\n");
		  exit(1);
	  }
	  
	  if ( fcntl(fd, F_SETLKW, &fl) == -1 )
	  {
		  perror("fcntl() failed.\n");
		  exit(1);
	  }
	  
	  if (instance_ == NULL)
	  {
		  instance_ = new T();
	  }
	  
	  fl.l_type = F_UNLCK;
	  if ( fcntl(fd, F_SETLK, &fl) == -1 )
	  {
		  perror("fcntl() failed.\n");
		  exit(1);
	  }
	  
	  return instance_;
  }
  
 private:
  static T* instance_;
};

template<typename T>
T* Singleton<T>::instance_ = NULL;

#endif /* __SINGLETON_H__ */
