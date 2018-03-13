/************************************************************************/
/* @file:	player.h                                                    */
/* @brief:	玩家类                                                      */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-23                                                  */
/* @last:	2017-06-23                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_PLAYER_H__
#define __WARLORD_GAMESVR_PLAYER_H__

#include "common.h"

#include <boost/pool/pool.hpp>
#include <boost/pool/object_pool.hpp>

#include "define/fight_define.h"
#include "define/res_define.h"

#include "container/hero_container.h"

class MemEnterSceneInfo;

class Player
{
public:
	Player();
	~Player();
	
public:
	bool				Init(int64_t _id);
	void				Destroy();
	
public:
	void				Update();
	
public:
	void				Attack(int64_t _stage_id);
	void				OnAttackFinish(MemEnterSceneInfo* scene_info);
	
public:
	int64_t				get_id()				{ return id_; }
	
	HeroContainer&		get_hero_container()	{ return hero_container_; }

private:
	int64_t				id_;
	
	HeroContainer		hero_container_;
};

#endif /* __WARLORD_GAMESVR_PLAYER_H__ */
