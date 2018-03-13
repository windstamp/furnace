#include "configure.h"

#include "log/log.h"

Configure::Configure(const std::string& _file_name)
	: file_name_(_file_name)
{
	Init();
}

Configure::Configure(const char *_file_name)
	: file_name_(_file_name)
{
	Init();
}

Configure::~Configure()
{
	file_stream_.close();
}

void Configure::Init()
{
	file_stream_.open(file_name_.c_str(), std::fstream::in);
}

std::string Configure::GetValue(const std::string &_section, const std::string &_key)
{
	std::string value;
	std::string line;
	std::string section;
	char tmp_line[ROW_LENGTH_MAX];
	bool find_section_pre = false;
	bool find_section_post = false;
	bool find_section_once = false;
	bool is_find_section = false;
	
	section.append(1, '[');
	section.append(_section);
	section.append(1, ']');
	
	file_stream_.seekg(0, file_stream_.beg);
	file_stream_.clear();
	
	do
	{
		memset(tmp_line, 0, ROW_LENGTH_MAX);
		file_stream_.getline(tmp_line, ROW_LENGTH_MAX - 1);
		line.assign(tmp_line);
		
		if (line.at(0) == '[')
		{
			if (!find_section_once) find_section_once = true;
			else break;
		}
		
		if ( line.compare(section) == 0 ) is_find_section = true;
		
		if (!is_find_section) continue;
	} while ( !file_stream_.eof() );
	
	return value;
}