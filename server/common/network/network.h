/*
 * =====================================================================================
 *
 *       Filename:  network.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/29/2015 04:06:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __NETWORK_H__
#define __NETWORK_H__ 1

#include <netdb.h>

#include "singleton.h"

class Network : public Singleton<Network>
{
 public:
  Network();
  ~Network();
 
 public:
  void PrintAddrinfo(const char *_message, struct addrinfo *_addrinfo);
};

#endif /* __NETWORK_H__ */
