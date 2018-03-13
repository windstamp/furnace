/************************************************************************/
/* @file:	ns_define.h                                                 */
/* @brief:	�����ռ�궨��                                                 */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-02-24                                                  */
/* @last:	2017-03-25                                                  */
/*                                                                      */
/* ���ļ�ֻ�ṩ�������ռ�ĺ궨�壬                                           */
/* ������Ҫ�õ������ռ�궨����ڲ�ͷ�ļ�����Ҫ�����������ļ�                      */
/************************************************************************/

#ifndef __WARLORD_COMMON_NS_DEFINE_H__
#define __WARLORD_COMMON_NS_DEFINE_H__

//-----------------------------------------------------------------------------
// �����ռ�
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
