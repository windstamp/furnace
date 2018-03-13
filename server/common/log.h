/*
 * @file    : log.h
 * @version : 1.0
 * @auth    : Zhang Keliang
 * @date    : 2016/02/29
 * @brief   : Log file.
 */
 
#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>
#include <stdarg.h>

const int LOG_INFO  = 1;
const int LOG_DEBUG = 2;
const int LOG_WARN  = 3;
const int LOG_ERROR = 4;
const int LOG_FATAL = 5;

const int LOG_LENGTH_MAX = 4096;

void Log(const int _priority, const char *_format, va_list &_ap);

#define DECLARE_LOG_FUNC(PriorityName, Priority) \
	inline void Log##PriorityName(const char *_format, const char *_file, const int _line, const char *_func, ...) \
	{ \
		static char format_buffer[LOG_LENGTH_MAX]; \
		snprintf(format_buffer, sizeof(format_buffer), "%s(%d)|%s|%s", _file, _line, _func, format_buffer); \
		va_list ap; \
		va_start(ap, _func); \
		Log(Priority, format_buffer, ap); \
		va_end(ap); \
	}

DECLARE_LOG_FUNC(Info,  LOG_INFO);
DECLARE_LOG_FUNC(Debug, LOG_DEBUG);
DECLARE_LOG_FUNC(Warn,  LOG_WARN);
DECLARE_LOG_FUNC(Error, LOG_ERROR);
DECLARE_LOG_FUNC(Fatal, LOG_ERROR);

#undef DECLARE_LOG_FUNC

#define LOG_INFO(format, args...)  LogWarn(format, __FILE__, __LINE__, __func__, ##args);
#define LOG_DEBUG(format, args...) LogDebug(format, __FILE__, __LINE__, __func__, ##args);
#define LOG_WARN(format, args...)  LogWarn(format, __FILE__, __LINE__, __func__, ##args);
#define LOG_ERROR(format, args...) LogError(format, __FILE__, __LINE__, __func__, ##args);
#define LOG_FATAL(format, args...) LogFatal(format, __FILE__, __LINE__, __func__, ##args);

#endif /* LOG_H_ */
