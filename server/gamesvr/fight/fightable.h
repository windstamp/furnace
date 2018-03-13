/************************************************************************/
/* @file:	fightable.h                                                 */
/* @brief:	战斗实体基类                                                */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-18                                                  */
/* @last:	2017-06-24                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_FIGHTABLE_H__
#define __WARLORD_GAMESVR_FIGHTABLE_H__

#include "common.h"

#include "define/res_define.h"

class Fightable
{
public:
	virtual			~Fightable()	{}
	
public:
	void			Init();
	virtual void	Destroy() = 0;
	
public:
	virtual void	Attack(Fightable* _entry) = 0;
	
public:
	virtual bool	IsDead() = 0;
	
protected:
	Fightable*			father_;
};

#endif /* __WARLORD_GAMESVR_FIGHTABLE_H__ */
