﻿/************************************************************************/
/* @file:	id_generator.h                                              */
/* @brief:	ID生成器                                                    */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-28                                                  */
/* @last:	2017-08-12                                                  */
/*                                                                      */
/* 负责全服各种ID生成                                                   */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_ID_GENERATOR_H__
#define __WARLORD_GAMESVR_ID_GENERATOR_H__

#include <pthread.h>

class IdGenerator
{
public:
	//-------------------------------------------------------------------------
	// 构造函数和析构函数
	//-------------------------------------------------------------------------
	IdGenerator();
	~IdGenerator();

public:
	//-------------------------------------------------------------------------
	// 初始化、销毁
	//-------------------------------------------------------------------------
	bool			Init(const int64_t _id, const int32_t _type);
	void			Destroy();
	
public:
	//-------------------------------------------------------------------------
	// 成员获取函数
	//-------------------------------------------------------------------------
	int32_t				get_type()		{ return type_; }
	
public:
	//-------------------------------------------------------------------------
	// 生成ID
	//-------------------------------------------------------------------------
	virtual int64_t		Generate()	= 0;
	
protected:
	//-------------------------------------------------------------------------
	// 成员变量
	//-------------------------------------------------------------------------
	int64_t			id_;
	int32_t			type_;
	
	pthread_mutex_t	lock_;
};

#endif	/* #ifndef __WARLORD_GAMESVR_ID_GENERATOR_H__ */