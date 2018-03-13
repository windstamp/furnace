/*
 * @file    : configure.h
 * @version : 1.0
 * @auth    : Zhang Keliang
 * @date    : 2016/02/29
 * @brief   : Parse information from configuration file.
 */
 
#ifndef CONFIGURE_H_
#define CONFIGURE_H_

#include <string.h>

#include <fstream>

#include "singleton.h"

#define ROW_LENGTH_MAX 256

class Configure : public Singleton<Configure>
{
 public:
	Configure(const std::string& _file_name);
	Configure(const char* _file_name);
	~Configure();
	
 public:
	void Init();
	
 public:
	std::string GetValue(const std::string &_section, const std::string &_key);
	
 private:
	std::string file_name_;
	std::fstream file_stream_;
};

#endif /* CONFIGURE_H_ */
