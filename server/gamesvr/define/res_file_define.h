/************************************************************************/
/* @file:	res_file_define.h                                           */
/* @brief:	静态资源文件路径定义                                        */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-03-28                                                  */
/* @last:	2017-07-02                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_RES_FILE_DEFINE_H__
#define __WARLORD_GAMESVR_RES_FILE_DEFINE_H__

//-----------------------------------------------------------------------------
// 配置文件目录
//-----------------------------------------------------------------------------
static const char * const RESOURCE_PATH					= "/home/smb/renshi/bitbucket/furnace/game/data/entry/";

//-----------------------------------------------------------------------------
// 任务相关配置文件路径 (Mission)
//-----------------------------------------------------------------------------
static const char * const MISSION_ENTRY_FILE				= "mission_entry.xml";
static const char * const MISSION_CONDITION_ENTRY_FILE		= "mission_condition_entry.xml";

//-----------------------------------------------------------------------------
// 排行榜相关配置文件路径 (Rank)
//-----------------------------------------------------------------------------
static const char * const RANK_ENTRY_FILE					= "rank_entry.xml";

//-----------------------------------------------------------------------------
// 武将基本信息及战斗信息相关配置文件 (Hero)
//-----------------------------------------------------------------------------
static const char * const HERO_BASE_ATT_ENTRY_FILE			= "hero_base_att_entry.xml";
static const char * const HERO_BASE_ENTRY_FILE				= "hero_base_entry.xml";
static const char * const HERO_ENTRY_FILE					= "hero_entry.xml";
static const char * const HERO_GROUP_ENTRY_FILE				= "hero_group_entry.xml";
static const char * const HERO_UPGRADE_ENTRY_FILE			= "hero_upgrade_entry.xml";
static const char * const SCENE_ENTRY_FILE					= "scene_entry.xml";

//-----------------------------------------------------------------------------
// 战斗相关配置文件路径 (Fight)
//-----------------------------------------------------------------------------
static const char * const PASSIVE_SKILL_ENTRY_FILE			= "passive_skill_entry.xml";
static const char * const SKILL_ENTRY_FILE					= "skill_entry.xml";

#endif /* __WARLORD_GAMESVR_RES_FILE_DEFINE_H__ */
