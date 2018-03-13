/************************************************************************/
/* @file:	scene_mgr.h                                                 */
/* @brief:	战斗场景管理类                                              */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-23                                                  */
/* @last:	2017-07-10                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_SCENE_MGR_H__
#define __WARLORD_GAMESVR_SCENE_MGR_H__

#include "common.h"
#include "define/fight_define.h"
#include "define/res_define.h"

class MemEnterSceneInfo;

class Scene;

class SceneMgr
{
	friend class Singleton<SceneMgr>;

private:
	//-------------------------------------------------------------------------
	// 构造函数和析构函数
	//-------------------------------------------------------------------------
	SceneMgr()	{}
	~SceneMgr()	{}
	
public:
	//-------------------------------------------------------------------------
	// 初始化 & 销毁
	//-------------------------------------------------------------------------
	bool			Init();
	void			Destroy();
	
public:
	//-------------------------------------------------------------------------
	// 注册战斗
	//-------------------------------------------------------------------------
	bool			Register(MemEnterSceneInfo* _info);
	
public:
	//-------------------------------------------------------------------------
	// 每帧更新
	//-------------------------------------------------------------------------
	void			Update();
	void			UpdateEnterSceneInfo();
	void			UpdateScene();
	
public:

private:
	void			DestroyScene(Scene* _scene);

public:
	//-------------------------------------------------------------------------
	// 成员获取函数
	//-------------------------------------------------------------------------
	int64_t							gen_serial()		{ return ++serial_ + ( (int64_t)1001 << 40 ); }
	
private:
	int64_t							serial_;

	std::list<MemEnterSceneInfo*>	enter_scene_info_list_;
	std::map<int32_t, Scene*>		scene_map_;
};

#define sSceneMgr	Singleton<SceneMgr>::Instance()

#endif /* __WARLORD_GAMESVR_SCENE_H__ */
