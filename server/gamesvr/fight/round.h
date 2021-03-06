﻿/************************************************************************/
/* @file:	round.h                                                     */
/* @brief:	战斗回合                                                    */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-21                                                  */
/* @last:	2017-07-21                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_ROUND_H__
#define __WARLORD_GAMESVR_ROUND_H__

#include "common.h"

class FightHero;

class Round
{
public:
	//-------------------------------------------------------------------------
	// 构造函数和析构函数
	//-------------------------------------------------------------------------
	Round();
	~Round();
	
public:
	//-------------------------------------------------------------------------
	// 初始化和销毁
	//-------------------------------------------------------------------------
	bool	Init(const int32_t _round);
	void	Destroy();
	void	Clear();
	
public:
	//-------------------------------------------------------------------------
	// 获取下一个攻击英雄
	//-------------------------------------------------------------------------
	FightHero*				ExtractNextAttackFightHero();
	
public:
	//-------------------------------------------------------------------------
	// 成员变量的 get/set 函数
	//-------------------------------------------------------------------------
	int32_t					get_round()							{ return round_; }
	void					set_round(const int32_t _round)		{ round_ = _round; }
	
	std::list<FightHero*>&	get_fight_hero_attack_list()		{ return fight_hero_attackk_list_; }
	
private:
	//-------------------------------------------------------------------------
	// 成员变量
	//-------------------------------------------------------------------------
	int32_t											round_;					// 当前是第几个回合
	std::list<FightHero*>							fight_hero_attackk_list_;		// 英雄出手顺序列表
};

#endif /* __WARLORD_GAMESVR_ROUND_H__ */
