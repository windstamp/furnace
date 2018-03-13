/************************************************************************/
/* @file:	object_pool_mgr.h                                           */
/* @brief:	����ع�����                                                */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-24                                                  */
/* @last:	2017-06-24                                                  */
/*                                                                      */
/* ��Ա����ȫ������Ϊpublic���������                                   */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_OBJECT_POOL_MGR_H__
#define __WARLORD_GAMESVR_OBJECT_POOL_MGR_H__

#include "common.h"

#include <boost/pool/pool.hpp>
#include <boost/pool/object_pool.hpp>

#include "define/fight_define.h"
#include "define/res_define.h"

#include "fight/fight_group.h"
#include "fight/fight_hero.h"
#include "fight/fight_util_object.h"
#include "fight/round.h"
#include "fight/scene.h"
#include "fight/skill.h"
#include "object/hero.h"
#include "player/player.h"

class ObjectPoolMgr
{
	friend class Singleton<ObjectPoolMgr>;
	
private:
	//-------------------------------------------------------------------------
	// ���캯������������
	//-------------------------------------------------------------------------
	ObjectPoolMgr()		{}
	~ObjectPoolMgr()	{}
	
public:
	//-------------------------------------------------------------------------
	// ��ʼ��������
	//-------------------------------------------------------------------------
	bool	Init();
	void	Destroy();
	
public:
	//-------------------------------------------------------------------------
	// ��Ա����
	//-------------------------------------------------------------------------
	boost::object_pool<MemEnterSceneInfo>	object_pool_scene_info;
	boost::object_pool<MemFightGroup>		object_pool_mem_fight_group;
	boost::object_pool<MemFightHero>		object_pool_mem_fight_hero;
	
	boost::object_pool<FightGroup>			object_pool_fight_group;
	boost::object_pool<FightHero>			object_pool_fight_hero;
	boost::object_pool<Hero>				object_pool_hero;
	boost::object_pool<Player>				object_pool_player;
	boost::object_pool<Round>				object_pool_round;
	boost::object_pool<Scene>				object_pool_scene;
	boost::object_pool<Skill>				object_pool_skill;
};

#define sObjectPoolMgr	Singleton<ObjectPoolMgr>::Instance()

#endif /* __WARLORD_GAMESVR_OBJECT_POOL_MGR_H__ */
