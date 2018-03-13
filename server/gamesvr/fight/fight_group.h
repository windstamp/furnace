/************************************************************************/
/* @file:	fight_group.h                                               */
/* @brief:	战斗阵容                                                    */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-18                                                  */
/* @last:	2017-07-21                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_FIGHT_GROUP_H__
#define __WARLORD_GAMESVR_FIGHT_GROUP_H__

#include "common.h"

#include "define/fight_define.h"
#include "define/res_define.h"

#include "fight/fightable.h"

class FightHero;
class Player;
class Scene;

class FightGroup
{
public:
	//-------------------------------------------------------------------------
	// 构造函数和析构函数
	//-------------------------------------------------------------------------
	FightGroup();
	~FightGroup();
	
public:
	//-------------------------------------------------------------------------
	// 初始化和销毁
	//-------------------------------------------------------------------------
	bool						Init(Scene* _scene, ECamp _camp);
	void						Destroy();
	
public:
	//-------------------------------------------------------------------------
	// 攻击、是否阵亡
	//-------------------------------------------------------------------------
	void						Attack(FightGroup* _fight_group);
	bool						IsDead();
	
public:
	//-------------------------------------------------------------------------
	// 成员变量的 get/set 函数
	//-------------------------------------------------------------------------
	Scene*						get_scene()		{ return scene_; }
	ECamp						get_camp()		{ return camp_;	}
	
	std::vector<FightHero*>&	get_fight_hero()	{ return fight_hero_vec_; }
	
	void						AddHero(FightHero* _fight_hero);
	
private:
	//-------------------------------------------------------------------------
	// 成员变量
	//-------------------------------------------------------------------------
	Scene*						scene_;
	ECamp						camp_;
	
	std::vector<FightHero*>		fight_hero_vec_;
};

#endif /* __WARLORD_GAMESVR_FIGHT_GROUP_H__ */
