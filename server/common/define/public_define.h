/************************************************************************/
/* @file:	public_define.h                                             */
/* @brief:	公共定义                                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-27                                                  */
/* @last:	2017-07-27                                                  */
/*                                                                      */
/* 1. 各种释放操作                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_COMMON_PUBLIC_DEFINE_H__
#define __WARLORD_COMMON_PUBLIC_DEFINE_H__


//-----------------------------------------------------------------------------
// 1. 各种释放操作
//-----------------------------------------------------------------------------
#ifndef SAFE_DEL
#define SAFE_DEL(p)				{ if(p) { delete(p);		(p) = NULL; } }
#endif

#ifndef SAFE_DEL_ARRAY
#define SAFE_DEL_ARRAY(p)		{ if(p) { delete[](p);		(p) = NULL; } }
#endif

#ifndef SAFE_FREE
#define SAFE_FREE(p)			{ if(p) { free(p);			(p) = NULL;} }
#endif

#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)			{ if(p) { (p)->Release();	(p) = NULL; } }
#endif


#endif	/* __WARLORD_COMMON_PUBLIC_DEFINE_H__ */

