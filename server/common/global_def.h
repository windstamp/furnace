/*
 * =====================================================================================
 *
 *       Filename:  global_def.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/10/2016 02:12:44 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef __GLOBAL_DEF_H__
#define __GLOBAL_DEF_H__

// 命名空间
#define NAMESPACE_BEGIN(name) namespace name {
#define NAMESPACE_END(name) }

// 安全删除指针
#define SAFE_DELETE(p) \
	do { \
		if (p) { \
			delete p; \
			p = NULL; \
		} \
	} while (false)

// 安全删除数组指针
#define SAFE_DELETE_ARRAY(p) \
	do { \
		if (p) { \
			delete p[]; \
			p = NULL; \
		}\
	} while(false)

// 安全删除一个VECTOR里面的指针
#define SAFE_DELETE_PTR_VECTOR(vec) \
	do { \
		for (size_t i = 0; i < vec.size(); ++i) { \
			SAFE_DELETE(vec[i]); \
		} \
		vec.clear(); \
	} while(false)

// 取得类型中成员的偏移
#define OFFSET_OF(type, name) ( ( (szie_t)&( (type*)1 )->name ) - 1 )

#endif /* __GLOBAL_DEF_H__ */
