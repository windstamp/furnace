/************************************************************************/
/* @file:	hero_container.h                                            */
/* @brief:	Ó¢ÐÛÈÝÆ÷Àà                                                  */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-07-11                                                  */
/* @last:	2017-07-11                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#ifndef __WARLORD_GAMESVR_HERO_CONTAINER_H__
#define __WARLORD_GAMESVR_HERO_CONTAINER_H__

#include "common.h"

class Hero;
class Player;

class HeroContainer
{
public:
	HeroContainer();
	~HeroContainer();
	
public:
	bool							Init(Player* _owner);
	
public:
	void							AddHero(const int64_t _type_id, const int64_t _owner_id);
	void							AddHero(Hero* _hero);
	Hero*							GetHeroById(const int64_t _id);
	bool							GetHeroByTypeId(const int64_t _type_id, std::vector<Hero*>& _vec_hero);

public:
	Player*							get_owner()		{ return owner_; }
	std::vector<Hero*>&				get_vec_hero()	{ return vec_hero_; }
	std::map<int64_t, Hero*>&		get_map_hero()	{ return map_hero_; }
	
private:
	Player*							owner_;
	
	std::vector<Hero*>				vec_hero_;	// 
	std::map<int64_t, Hero*>		map_hero_;	// <id, Hero*>
};

#endif /* #ifndef __WARLORD_GAMESVR_HERO_CONTAINER_H__ */
