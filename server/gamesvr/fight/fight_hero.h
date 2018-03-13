/************************************************************************/
/* @file:	fight_hero.h                                                */
/* @brief:	战斗英雄                                                    */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-18                                                  */
/* @last:	2017-07-21                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_FIGHT_HERO_H__
#define __WARLORD_GAMESVR_FIGHT_HERO_H__

#include "common.h"

#include "define/res_define.h"
#include "define/hero_define.h"

class MemFightHero;

class FightGroup;
class Hero;
class Skill;

class FightHero
{
public:
	//-------------------------------------------------------------------------
	// 构造函数和析构函数
	//-------------------------------------------------------------------------
	FightHero();
	~FightHero();
	
public:
	//-------------------------------------------------------------------------
	// 初始化和销毁
	//-------------------------------------------------------------------------
	bool						Init(const MemHeroEntry* _hero_entry, FightGroup* _fight_group, const int64_t _owner_id, const int32_t _pos);
	bool						Init(MemFightHero* _mem_fight_hero, FightGroup* _fight_group);
	bool						Init(Hero* _hero, FightGroup* _fight_group, const int64_t _owner_id);
	
	void						Destroy();
	
public:
	//-------------------------------------------------------------------------
	// 攻击、是否阵亡
	//-------------------------------------------------------------------------
	void						Attack();
	bool						IsDead();
	
private:
	//-------------------------------------------------------------------------
	// 获取攻击目标
	//-------------------------------------------------------------------------
	void						GetAttackTarget(std::list<FightHero*>& _fight_hero_target);
	void						Attack(FightHero* _target_fight_hero);
	
private:
	//-------------------------------------------------------------------------
	// 响应函数
	//-------------------------------------------------------------------------
	void						OnAttChange();
	void						OnDead();
	
private:
	//-------------------------------------------------------------------------
	// 日志函数
	//-------------------------------------------------------------------------
	void						LogFightAtt();
	
public:
	//-------------------------------------------------------------------------
	// 成员变量的 get/set 函数
	//-------------------------------------------------------------------------
	FightGroup*					get_fight_group()		{ return fight_group_; }
	int64_t						get_owner_id()			{ return owner_id_; }
	int32_t						get_pos()				{ return pos_; }
	
	const MemHeroEntry*			get_hero_entry()		{ return hero_entry_; }
	MemFightHero*				get_fight_hero()		{ return fight_hero_; }
	Hero*						get_hero()				{ return hero_; }
	
	int64_t						get_hero_type_id()		{ return hero_entry_ ? hero_entry_->id : 0; }
	
	Skill*						get_common_skill()		{ return common_skill_; }
	Skill*						get_profound_skill()	{ return profound_skill_; }
	int64_t						get_common_skill_cd()	{ return common_skill_cd_; }
	int32_t						get_rage()				{ return rage_; }
	
	void						add_rage(const int32_t _rage);
	void						set_rage(const int32_t _rage)		{ rage_ = _rage; }
	
	std::map<int32_t, int32_t>&	get_fight_att()			{ return fight_att_; };
	
private:
	//-------------------------------------------------------------------------
	// 成员变量
	//-------------------------------------------------------------------------
	FightGroup*					fight_group_;
	int64_t						owner_id_;
	int32_t						pos_;
	
	const MemHeroEntry*			hero_entry_;
	MemFightHero*				fight_hero_;
	Hero*						hero_;
	
	Skill*						common_skill_;			// 普攻
	Skill*						profound_skill_;		// 奥义技能
	int64_t						common_skill_cd_;		// 普攻CD
	int32_t						rage_;					// 当前怒气值
	
	std::map<int32_t, int32_t>	fight_att_;				// <EHeroAtt, value>
};

#endif /* __WARLORD_GAMESVR_FIGHT_HERO_H__ */
