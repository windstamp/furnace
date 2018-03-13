/************************************************************************/
/* @file:	hero.h                                                      */
/* @brief:	”¢–€–≈œ¢                                                    */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-23                                                  */
/* @last:	2017-07-11                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_HERO_H__
#define __WARLORD_GAMESVR_HERO_H__

#include "common.h"

#include "define/res_define.h"

class Hero
{
public:
	Hero();
	~Hero();
	Hero(const Hero& rhs);
	
	Hero& operator=(const Hero& rhs);
	
public:
	bool					Init(const int64_t _hero_type_id, const int64_t _owner_id, const int32_t _pos);
	bool					Init(const MemHeroEntry* _hero_entry, const int64_t _owner_id, const int32_t _pos);
	
public:
	bool					GetAtt(std::map<int32_t, int32_t>& _fight_att);
	
public:
	int64_t					get_id()				{ return id_; }
	int32_t					get_pos()				{ return pos_; }
	int64_t					get_owner_id()			{ return owner_id_; }
	
	const MemHeroEntry*		get_hero_entry()		{ return hero_entry_; }
	int64_t					get_hero_type_id()		{ return hero_entry_ ? hero_entry_->id : 0; }
	
private:
	int64_t					id_;
	int64_t					hero_type_id_;
	int64_t					owner_id_;
	int32_t					pos_;
	
	const MemHeroEntry*		hero_entry_;
};

#endif /* __WARLORD_GAMESVR_HERO_H__ */
