#include <iostream>
#include <string>

// boost library
//#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
//#include <boost/log/expressions.hpp>
//#include <boost/log/sinks/text_file_backend.hpp>
//#include <boost/log/utility/setup/file.hpp>
//#include <boost/log/utility/setup/common_attributes.hpp>
//#include <boost/log/sources/severity_logger.hpp>
//#include <boost/log/sources/record_ostream.hpp>
namespace logging = boost::log;

#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include "resource/res_mgr.h"

namespace pt = boost::property_tree;

//-----------------------------------------------------------------------------
// 加载静态属性列表
//-----------------------------------------------------------------------------
static const pt::ptree& empty_ptree(){
	static pt::ptree t;
	return t;
}

bool ResMgr::LoadHeroBaseAttEntryList()
{
	bool ret = true;

	hero_entry_map_.clear();
	
	pt::ptree tree;
	std::stringstream filename;
	filename << RESOURCE_PATH << HERO_BASE_ATT_ENTRY_FILE;
	BOOST_LOG_TRIVIAL(debug) << "filename = " << filename.str();
	pt::read_xml(filename.str().c_str(), tree);
	const pt::ptree &rows = tree.get_child("rows", empty_ptree());
	BOOST_FOREACH(const pt::ptree::value_type &row, rows)
	{
		const pt::ptree &attrs = row.second.get_child("<xmlattr>", empty_ptree());
		
		MemHeroBaseAttEntry entry;
		int64_t id = 0;
		int32_t max_hp = 0, attack = 0, defence = 0;
		int32_t hit = 0, dodge = 0;
		int32_t crit = 0, decrit = 0;
		int32_t broken = 0, block = 0;
		int32_t max_rage = 0, init_rage = 0;
		int32_t speed = 0;
		
		BOOST_FOREACH(const pt::ptree::value_type &v, attrs)
		{
			
			std::string att = v.first.data();
			std::string val = v.second.data();
			
			if (att == "id")
			{
				sscanf(val.c_str(), "%ld", &id);
				
				entry.id = id;
			}
			else if (att == "max_hp")
			{				
				sscanf(val.c_str(), "%d", &max_hp);
			}
			else if (att == "attack")
			{				
				sscanf(val.c_str(), "%d", &attack);
			}
			else if (att == "defence")
			{				
				sscanf(val.c_str(), "%d", &defence);
			}
			else if (att == "hit")
			{				
				sscanf(val.c_str(), "%d", &hit);
			}
			else if (att == "dodge")
			{				
				sscanf(val.c_str(), "%d", &dodge);
			}
			else if (att == "crit")
			{				
				sscanf(val.c_str(), "%d", &crit);
			}
			else if (att == "decrit")
			{				
				sscanf(val.c_str(), "%d", &decrit);
			}
			else if (att == "broken")
			{				
				sscanf(val.c_str(), "%d", &broken);
			}
			else if (att == "block")
			{				
				sscanf(val.c_str(), "%d", &block);
			}
			else if (att == "max_rage")
			{				
				sscanf(val.c_str(), "%d", &max_rage);
			}
			else if (att == "init_rage")
			{				
				sscanf(val.c_str(), "%d", &init_rage);
			}
			else if (att == "speed")
			{				
				sscanf(val.c_str(), "%d", &speed);
			}
		}
			
		BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "id=\"" << id << "\"\t"
			<< "max_hp=\"" << max_hp << "\"\t"
			<< "attack=\"" << attack << "\"\t"
			<< "defence=\"" << defence << "\"\t"
			<< "hit=\"" << hit << "\"\t"
			<< "dodge=\"" << dodge << "\"\t"
			<< "crit=\"" << crit << "\"\t"
			<< "decrit=\"" << decrit << "\"\t"
			<< "broken=\"" << broken << "\"\t"
			<< "block=\"" << block << "\"\t"
			<< "max_rage=\"" << max_rage << "\"\t"
			<< "init_rage=\"" << init_rage << "\"\t"
			<< "speed=\"" << speed << "\"\t"
			<< "";
		
		entry.fight_att[EHA_MaxHp]			= max_hp;
		entry.fight_att[EHA_AttackPower]	= attack;
		entry.fight_att[EHA_DefenceMelee]	= defence;
		entry.fight_att[EHA_DefenceMagic]	= defence;
		entry.fight_att[EHA_Hit]			= hit;
		entry.fight_att[EHA_Dodge]			= dodge;
		entry.fight_att[EHA_Crit]			= crit;
		entry.fight_att[EHA_Decrit]		= decrit;
		entry.fight_att[EHA_Broken]		= broken;
		entry.fight_att[EHA_Block]			= block;
		entry.fight_att[EHA_MaxRage]		= max_rage;
		entry.fight_att[EHA_InitRage]		= init_rage;
		entry.fight_att[EHA_Speed]			= speed;
		
		hero_base_att_entry_map_[id] = entry;
	}
	
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "total num = " << hero_base_att_entry_map_.size();

	return ret;
}


//-----------------------------------------------------------------------------
// 获得各资源项属性
//-----------------------------------------------------------------------------
const MemHeroBaseAttEntry* ResMgr::GetHeroBaseAttEntry(const int64_t id) const
{
	std::map<int64_t, MemHeroBaseAttEntry>::const_iterator iter;
	std::map<int64_t, MemHeroBaseAttEntry>::const_iterator iter_end;	
	
	iter = hero_base_att_entry_map_.find(id);
	iter_end = hero_base_att_entry_map_.cend();
	
	if (iter != iter_end)
		return &(iter->second);
	
	return NULL;
}
