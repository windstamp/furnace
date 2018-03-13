/************************************************************************/
/* @file:	fight_helper.h                                              */
/* @brief:	战斗辅助函数                                                */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-23                                                  */
/* @last:	2017-07-13                                                  */
/*                                                                      */
/* 一系列静态辅助函数                                                   */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_FIGHT_HELPER_H__
#define __WARLORD_GAMESVR_FIGHT_HELPER_H__

#include "common.h"
#include "define/res_define.h"
#include "define/hero_define.h"
#include "define/fight_define.h"

class MemFightGroup;
class MemFightHero;

class Hero;
class Player;

NAMESPACE_BEGIN(fight_helper)

bool UpdateHeroAtt(const std::map<int32_t, int32_t>& _src_fight_att, std::map<int32_t, int32_t>& _dst_fight_att);

bool BuildHeroAtt(std::map<int32_t, int32_t>& _fight_att, const MemHeroEntry* _entry, const int64_t _owner_id);

bool BuildHeroAtt(std::map<int32_t, int32_t>& _fight_att, Hero* _hero, int64_t _owner_id);

bool BuildHeroAtt(std::map<int32_t, int32_t>& _fight_att, MemFightHero* _mem_fight_hero, int64_t _owner_id);

bool BuildFightGroup(MemFightGroup* _dst_fight_group, Player* _player);

bool BuildFightGroup(MemFightGroup* _dst_fight_group, const int64_t _fight_group_id);

bool BuildFightGroup(MemFightGroup* _dst_fight_group, MemFightGroup* _src_fight_group);

NAMESPACE_END(fight_helper)

#endif /* __WARLORD_GAMESVR_FIGHT_HELPER_H__ */
