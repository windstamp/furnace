/************************************************************************/
/* @file:	ns_define.h                                                 */
/* @brief:	命名空间宏定义                                                 */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-02-24                                                  */
/* @last:	2017-03-25                                                  */
/*                                                                      */
/* 本文件只提供了命名空间的宏定义，                                           */
/* 凡是需要用到命名空间宏定义的内部头文件都需要单独包含本文件                      */
/************************************************************************/

#ifndef __WARLORD_COMMON_NS_DEFINE_H__
#define __WARLORD_COMMON_NS_DEFINE_H__

//-----------------------------------------------------------------------------
// 命名空间
//-----------------------------------------------------------------------------
// namespace name
#define NAMESPACE_BEGIN(name)	namespace name {
#define NAMESPACE_END(name)		}
#define USING_NAMESPACE(name)	using namespace name;

// namespace warlord
#define NS_WARLORD_BEGIN		NAMESPACE_BEGIN(warlord)
#define NS_WARLORD_END			NAMESPACE_END(warlord)
#define USING_NS_WARLORD		USING_NAMESPACE(warlord)

// namespace warlord::common
#define NS_WARLORD_COMMON_BEGIN		NAMESPACE_BEGIN(warlord)	\
									NAMESPACE_BEGIN(common)
#define NS_WARLORD_COMMON_END		NAMESPACE_END(warlord)		\
									NAMESPACE_END(common)
#define USING_NS_WARLORD_COMMON		USING_NAMESPACE(warlord::common)

// namespace warlord::dbpool
#define NS_WARLORD_DBPOOL_BEGIN		NAMESPACE_BEGIN(warlord)	\
									NAMESPACE_BEGIN(dbpool)
#define NS_WARLORD_DBPOOL_END		NAMESPACE_END(warlord)		\
									NAMESPACE_END(dbpool)
#define USING_NS_WARLORD_DBPOOL		USING_NAMESPACE(warlord::dbpool)

#endif /* __WARLORD_COMMON_NS_DEFINE_H__ */
