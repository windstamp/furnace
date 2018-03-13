#include "string_tool.h"

std::string truncate(const std::string &_str)
{
	std::string tmp = truncate_front(_str);
	
	return truncate_back(tmp);
}

std::string truncate_front(const std::string &_str)
{
	int count = 0;
	int length = _str.length();
	
	for (std::string::const_iterator iter = _str.begin();
		 iter != _str.end();
		 ++iter)
	{
		 if (*iter != ' ' || *iter != '\t') break;
		 
		 if (*iter == ' ' || *iter == '\t') ++count;
	}
	
	return _str.substr(count, length - count);
}

std::string truncate_back(const std::string &_str)
{
	
	int count = 0;
	int length = _str.length();
	
	for (std::string::const_reverse_iterator iter = _str.rbegin();
		 iter != _str.rend();
		 ++iter)
	{
		 if (*iter != ' ' || *iter != '\t') break;
		 
		 if (*iter == ' ' || *iter == '\t') ++count;
	}
	
	return _str.substr(0, length - count);
}