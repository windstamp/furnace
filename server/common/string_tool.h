/*
 * @file    : string_tool.h
 * @version : 1.0
 * @auth    : Zhang Keliang
 * @date    : 2016/02/29
 * @brief   : String tools.
 */
 
#ifndef STRING_TOOL_H_
#define STRING_TOOL_H_

#include <string>

std::string truncate(const std::string &_str);

std::string truncate_front(const std::string &_str);

std::string truncate_back(const std::string &_str);

#endif /* STRING_TOOL_H_ */
