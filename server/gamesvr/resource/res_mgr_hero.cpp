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

bool ResMgr::LoadHeroBaseEntryList()
{
	bool ret = true;
	
	hero_base_entry_map_.clear();
	
	pt::ptree tree;
	std::stringstream filename;
	filename << RESOURCE_PATH << HERO_BASE_ENTRY_FILE;
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "filename = " << filename.str();
	pt::read_xml(filename.str().c_str(), tree);
	const pt::ptree &rows = tree.get_child("rows", empty_ptree());
	BOOST_FOREACH(const pt::ptree::value_type &row, rows)
	{
		const pt::ptree &attrs = row.second.get_child("<xmlattr>", empty_ptree());
		
		MemHeroBaseEntry entry;
		int64_t id = 0; std::string name;
		int32_t position = 0; int32_t damage_type = 0;
		int64_t common_skill_id = 0; int64_t profound_skill_id = 0;
		
		BOOST_FOREACH(const pt::ptree::value_type &v, attrs)
		{
			std::string att = v.first.data();
			std::string val = v.second.data();
			
			if (att == "id")
			{
				sscanf(val.c_str(), "%ld", &id);
				
				entry.id = id;
			}
			else if (att == "name")
			{
				name = val;
			}
			else if (att == "position")
			{
				sscanf(val.c_str(), "%d", &position);
				
				entry.position = position;
			}
			else if (att == "damage_type")
			{
				sscanf(val.c_str(), "%d", &damage_type);
				
				entry.damage_type = damage_type;
			}
			else if (att == "common_skill_id")
			{
				sscanf(val.c_str(), "%ld", &common_skill_id);
				
				entry.common_skill_id = common_skill_id;
			}
			else if (att == "profound_skill_id")
			{
				sscanf(val.c_str(), "%ld", &profound_skill_id);
				
				entry.profound_skill_id = profound_skill_id;
			}
		}

		BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "id=\"" << id << "\"\t"
			<< "name=\"" << name << "\"\t"
			<< "position=\"" << position << "\"\t"
			<< "damage_type=\"" << damage_type << "\"\t"
			<< "common_skill_id=\"" << common_skill_id << "\"\t"
			<< "profound_skill_id=\"" << profound_skill_id << "\"\t"
			<< "";
		
		const MemHeroBaseAttEntry* base_att_entry = GetHeroBaseAttEntry(entry.id);
		if (!base_att_entry)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "Load base_att_entry failed for entry: " << entry.id;
				
			return false;
		}
			
		entry.base_att_entry = base_att_entry;
		
		const MemSkillEntry* common_skill_entry = GetSkillEntry(entry.common_skill_id);
		if (!common_skill_entry)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "Load common_skill_entry failed for entry: " << entry.id << " common_skill_id: "
				<< entry.common_skill_id;
				
			return false;
		}
		
		entry.common_skill_entry = common_skill_entry;
		
		const MemSkillEntry* profound_skill_entry = GetSkillEntry(entry.profound_skill_id);
		if (!profound_skill_entry)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "Load profound_skill_entry failed for entry: " << entry.id;
				
			return false;
		}
		
		entry.profound_skill_entry = profound_skill_entry;
		
		hero_base_entry_map_[id] = entry;
	}
	
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "total num = " << hero_base_entry_map_.size();

	return ret;
}

bool ResMgr::LoadHeroEntryList()
{
	bool ret = true;
	
	hero_entry_map_.clear();
	
	pt::ptree tree;
	std::stringstream filename;
	filename << RESOURCE_PATH << HERO_ENTRY_FILE;
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "filename = " << filename.str();
	pt::read_xml(filename.str().c_str(), tree);
	const pt::ptree &rows = tree.get_child("rows", empty_ptree());
	BOOST_FOREACH(const pt::ptree::value_type &row, rows)
	{
		const pt::ptree &attrs = row.second.get_child("<xmlattr>", empty_ptree());
		
		MemHeroEntry entry;
		int64_t id = 0;
		int64_t type_id = 0;
		int32_t quality = 0;
		int32_t att_type_1 = 0, att_value_1 = 0;
		int32_t att_type_2 = 0, att_value_2 = 0;
		
		BOOST_FOREACH(const pt::ptree::value_type &v, attrs)
		{
			std::string att = v.first.data();
			std::string val = v.second.data();
			
			if (att == "id")
			{
				sscanf(val.c_str(), "%ld", &id);
				
				entry.id = id;
			}
			else if (att == "type_id")
			{
				sscanf(val.c_str(), "%ld", &type_id);
				
				entry.type_id = type_id;
			}
			else if (att == "quality")
			{
				sscanf(val.c_str(), "%d", &quality);
				
				entry.quality = quality;
			}
			else if (att == "att_type_1")
			{
				sscanf(val.c_str(), "%d", &att_type_1);
			}
			else if (att == "att_value_1")
			{
				sscanf(val.c_str(), "%d", &att_value_1);
			}
			else if (att == "att_type_2")
			{
				sscanf(val.c_str(), "%d", &att_type_2);
			}
			else if (att == "att_value_2")
			{
				sscanf(val.c_str(), "%d", &att_value_2);
			}
		}
		
		BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "id=\"" << id << "\"\t"
			<< "type_id=\"" << type_id << "\"\t"
			<< "quality=\"" << quality << "\"\t"
			<< "att_type_1=\"" << att_type_1 << "\"\t"
			<< "att_value_1=\"" << att_value_1 << "\"\t"
			<< "att_type_2=\"" << att_type_2 << "\"\t"
			<< "att_value_2=\"" << att_value_2 << "\"\t"
			<< "";
		
		if (att_value_1 != 0)
			entry.fight_att[att_type_1] = att_value_1;
		if (att_value_2 != 0)
		entry.fight_att[att_type_2] = att_value_2;
		
		const MemHeroBaseEntry* base_entry = GetHeroBaseEntry(entry.type_id);
		if (!base_entry)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "Load base_entry failed for entry: " << entry.id << " type_id: " << entry.type_id;
				
			return false;
		}
		
		entry.base_entry = base_entry;
		
		hero_entry_map_[id] = entry;
	}
	
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "total num = " << hero_entry_map_.size();

	return ret;
}

bool ResMgr::LoadHeroUpgradeEntryList()
{
	bool ret = true;
	
	hero_upgrade_entry_map_.clear();

	pt::ptree tree;
	std::stringstream filename;
	filename << RESOURCE_PATH << HERO_UPGRADE_ENTRY_FILE;
	BOOST_LOG_TRIVIAL(debug) << "filename = " << filename.str();
	pt::read_xml(filename.str().c_str(), tree);
	const pt::ptree &rows = tree.get_child("rows", empty_ptree());
	BOOST_FOREACH(const pt::ptree::value_type &row, rows)
	{
		const pt::ptree &attrs = row.second.get_child("<xmlattr>", empty_ptree());
		
		MemHeroUpgradeEntry entry;
		int64_t id = 0; int64_t src_id = 0; int64_t dst_id = 0;
		int64_t cost_hero_id_1 = 0, cost_hero_id_2 = 0;
		int32_t cost_hero_num_1 = 0, cost_hero_num_2 = 0;
		int64_t cost_item_id_1 = 0, cost_item_id_2 = 0;
		int32_t cost_item_num_1 = 0, cost_item_num_2 = 0;
		
		BOOST_FOREACH(const pt::ptree::value_type &v, attrs)
		{
			std::string att = v.first.data();
			std::string val = v.second.data();
			
			if (att == "id")
			{
				sscanf(val.c_str(), "%ld", &id);
				
				entry.id = id;
			}
			else if (att == "src_id")
			{
				sscanf(val.c_str(), "%ld", &src_id);
				
				entry.src_id = src_id;
			}
			else if (att == "dst_id")
			{
				sscanf(val.c_str(), "%ld", &dst_id);
				
				entry.dst_id = dst_id;
			}
			else if (att == "cost_hero_id_1")
			{
				sscanf(val.c_str(), "%ld", &cost_hero_id_1);
			}
			else if (att == "cost_hero_num_1")
			{
				sscanf(val.c_str(), "%d", &cost_hero_num_1);
			}
			else if (att == "cost_hero_id_2")
			{
				sscanf(val.c_str(), "%ld", &cost_hero_id_2);
			}
			else if (att == "cost_hero_num_2")
			{
				sscanf(val.c_str(), "%d", &cost_hero_num_2);
			}
			else if (att == "cost_item_id_1")
			{
				sscanf(val.c_str(), "%ld", &cost_item_id_1);
			}
			else if (att == "cost_item_num_1")
			{
				sscanf(val.c_str(), "%d", &cost_item_num_1);
			}
			else if (att == "cost_item_id_2")
			{
				sscanf(val.c_str(), "%ld", &cost_item_id_2);
			}
			else if (att == "cost_item_num_2")
			{
				sscanf(val.c_str(), "%d", &cost_item_num_2);
			}
		}
		
		BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "id=\"" << id << "\"\t"
			<< "src_id=\"" << src_id << "\"\t"
			<< "dst_id=\"" << dst_id << "\"\t"
			<< "cost_hero_id_1=\"" << cost_hero_id_1 << "\"\t"
			<< "cost_hero_num_1=\"" << cost_hero_num_1 << "\"\t"
			<< "cost_hero_id_2=\"" << cost_hero_id_2 << "\"\t"
			<< "cost_hero_num_2=\"" << cost_hero_num_2 << "\"\t"
			<< "cost_item_id_1=\"" << cost_item_id_1 << "\"\t"
			<< "cost_item_num_1=\"" << cost_item_num_1 << "\"\t"
			<< "cost_item_id_2=\"" << cost_item_id_2 << "\"\t"
			<< "cost_item_num_2=\"" << cost_item_num_2 << "\"\t"
			<< "";
		
		if ( (cost_hero_id_1 != 0) && (cost_hero_num_1 != 0) )
			entry.cost_hero[cost_hero_id_1] = cost_hero_num_1;
		if ( (cost_hero_id_2 != 0) && (cost_hero_num_2 != 0) )
			entry.cost_hero[cost_hero_id_2] = cost_hero_num_2;
		if ( (cost_item_id_1 != 0) && (cost_item_num_1 != 0) )
			entry.cost_hero[cost_item_id_1] = cost_item_num_1;
		if ( (cost_item_id_2 != 0) && (cost_item_num_2 != 0) )
			entry.cost_hero[cost_item_id_2] = cost_item_num_2;
		
		const MemHeroEntry* src_entry = GetHeroEntry(entry.src_id);		
		if (!src_entry)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "Load src_entry failed for entry: " << entry.id << " src_id: " << entry.src_id;
				
			return false;
		}
		
		entry.src_entry = src_entry;
		
		const MemHeroEntry* dst_entry = GetHeroEntry(entry.dst_id);
		if (!dst_entry)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "Load dst_entry failed for entry: " << entry.id << " dst_id: " << entry.dst_id;
				
			return false;
		}
			
		entry.dst_entry = dst_entry;
		
		hero_upgrade_entry_map_[id] = entry;
	}
	
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "total num = " << hero_upgrade_entry_map_.size();

	return ret;
}


//-----------------------------------------------------------------------------
// 获得各资源项属性
//-----------------------------------------------------------------------------
const MemHeroBaseEntry*	ResMgr::GetHeroBaseEntry(const int64_t id) const
{
	std::map<int64_t, MemHeroBaseEntry>::const_iterator iter;
	std::map<int64_t, MemHeroBaseEntry>::const_iterator iter_end;	
	
	iter = hero_base_entry_map_.find(id);
	iter_end = hero_base_entry_map_.cend();
	
	if (iter != iter_end)
		return &(iter->second);
	
	return NULL;
}

const MemHeroEntry* ResMgr::GetHeroEntry(const int64_t id) const
{
	std::map<int64_t, MemHeroEntry>::const_iterator iter;
	std::map<int64_t, MemHeroEntry>::const_iterator iter_end;	
	
	iter = hero_entry_map_.find(id);
	iter_end = hero_entry_map_.cend();
	
	if (iter != iter_end)
		return &(iter->second);
	
	return NULL;
}
