#include "log.h"

#include <string.h>

void Log(const int _priority, const char *_format, va_list &_ap)
{
	char file_name[80];
	
	switch(_priority)
	{
		case LOG_INFO:
		{
			strcat(file_name, "log_info.txt");
			break;
		}
		case LOG_DEBUG:
		{
			strcat(file_name, "log_debug.txt");
			break;
		}
		case LOG_WARN:
		{
			strcat(file_name, "log_warn.txt");
			break;
		}
		case LOG_ERROR:
		case LOG_FATAL:
		{
			strcat(file_name, "log_error.txt");
			break;
		}
		default:
		{
			strcat(file_name, "log_warn.txt");
			break;
		}
	}
	
	FILE *file = fopen(file_name, "a");
	
	if (!file)
	{
		fprintf(stderr, "Open file %s failed.", file_name);
		return;
	}
	
	vfprintf(file, _format, _ap);
	
	fclose(file);
}
