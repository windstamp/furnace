/*
 * =====================================================================================
 *
 *       Filename:  network.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/29/2015 04:06:45 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <arpa/inet.h>

#include "network/network.h"

Network::Network()
{	
}

Network::~Network()
{	
}

void Network::PrintAddrinfo(const char *_message, struct addrinfo *_addrinfo)
{
	printf("IP addresses for %s:\n", _message);
	
	char ipstr[INET6_ADDRSTRLEN];
	void *addr;
	char *ipversion;
	
	for (struct addrinfo *p = _addrinfo; p != NULL; p = p->ai_next)
	{
		if (p->ai_family == AF_INET)
		{
			struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
			addr = &(ipv4->sin_addr);
			ipversion = (char *)"IPv4";
		}
		else if (p->ai_family == AF_INET6)
		{
			struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
			addr = &(ipv6->sin6_addr);
			ipversion = (char *)"IPv6";
		}
		else
		{
			fprintf(stderr, "WARNING: address family is neither AF_INET nor AF_INET6 (%d)\n", p->ai_family);
			continue;
		}
		
		inet_ntop(p->ai_family, addr, ipstr, sizeof(ipstr));
		printf("  %s: %s\n", ipversion, ipstr);
	}
	
	return;
}
