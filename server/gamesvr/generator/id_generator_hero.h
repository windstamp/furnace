/************************************************************************/
/* @file:	id_generator_hero.h                                         */
/* @brief:	英雄ID生成器                                                */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-28                                                  */
/* @last:	2017-07-28                                                  */
/*                                                                      */
/* 负责全服英雄ID生成                                                   */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_ID_GENERATOR_HERO_H__
#define __WARLORD_GAMESVR_ID_GENERATOR_HERO_H__

class IdGenerator;

class IdGeneratorHero : public IdGenerator
{
public:
	//-------------------------------------------------------------------------
	// 构造函数和析构函数
	//-------------------------------------------------------------------------
	IdGeneratorHero();
	~IdGeneratorHero();

public:
	//-------------------------------------------------------------------------
	// 初始化、销毁
	//-------------------------------------------------------------------------
	bool			Init(const int64_t _id, const int32_t _type);
	void			Destroy();
	
public:
	//-------------------------------------------------------------------------
	// 生成ID
	//-------------------------------------------------------------------------
	int64_t			Generate();
};

#endif	/* #ifndef __WARLORD_GAMESVR_ID_GENERATOR_HERO_H__ */
