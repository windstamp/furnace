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

bool ResMgr::LoadSkillEntryList()
{
	bool ret = true;

	skill_entry_map_.clear();
	
	pt::ptree tree;
	std::stringstream filename;
	filename << RESOURCE_PATH << SKILL_ENTRY_FILE;
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "filename = " << filename.str();
	pt::read_xml(filename.str().c_str(), tree);
	const pt::ptree &rows = tree.get_child("rows", empty_ptree());
	BOOST_FOREACH(const pt::ptree::value_type &row, rows)
	{
		const pt::ptree &attrs = row.second.get_child("<xmlattr>", empty_ptree());
		
		MemSkillEntry entry;
		int64_t id = 0;
		int32_t target_type = 0, target_param = 0;
		int32_t effect_type = 0, effect_param = 0;
		
		BOOST_FOREACH(const pt::ptree::value_type &v, attrs)
		{			
			std::string att = v.first.data();
			std::string val = v.second.data();
			
			if (att == "id")
			{
				sscanf(val.c_str(), "%ld", &id);
				
				entry.id = id;
			}
			else if (att == "target_type")
			{				
				sscanf(val.c_str(), "%d", &target_type);
				
				entry.target_type = target_type;
			}
			else if (att == "target_param")
			{				
				sscanf(val.c_str(), "%d", &target_param);
				
				entry.target_param = target_param;
			}
			else if (att == "effect_type")
			{				
				sscanf(val.c_str(), "%d", &effect_type);
				
				entry.effect_type = effect_type;
			}
			else if (att == "effect_param")
			{				
				sscanf(val.c_str(), "%d", &effect_param);
				
				entry.effect_param = effect_param;
			}
		}
						
		BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "id=\"" << id << "\"\t"
			<< "target_type=\"" << target_type << "\"\t"
			<< "target_param=\"" << target_param << "\"\t"
			<< "effect_type=\"" << effect_type << "\"\t"
			<< "effect_param=\"" << effect_param << "\"\t"
			<< "";
		
		skill_entry_map_[id] = entry;
	}
	
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "total num = " << skill_entry_map_.size();

	return ret;
}

bool ResMgr::LoadPassiveSkillEntryList()
{
	bool ret = true;

	passive_skill_entry_map_.clear();
	
	pt::ptree tree;
	std::stringstream filename;
	filename << RESOURCE_PATH << PASSIVE_SKILL_ENTRY_FILE;
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "filename = " << filename.str();
	pt::read_xml(filename.str().c_str(), tree);
	const pt::ptree &rows = tree.get_child("rows", empty_ptree());
	BOOST_FOREACH(const pt::ptree::value_type &row, rows)
	{
		const pt::ptree &attrs = row.second.get_child("<xmlattr>", empty_ptree());
		
		MemPassiveSkillEntry entry;
		int64_t id = 0;
		int32_t condition_type = 0, condition_param = 0;
		int64_t skill_id = 0;
		
		BOOST_FOREACH(const pt::ptree::value_type &v, attrs)
		{			
			std::string att = v.first.data();
			std::string val = v.second.data();
			
			if (att == "id")
			{
				sscanf(val.c_str(), "%ld", &id);
				
				entry.id = id;
			}
			else if (att == "condition_type")
			{				
				sscanf(val.c_str(), "%d", &condition_type);
				
				entry.condition_type = condition_type;
			}
			else if (att == "condition_param")
			{				
				sscanf(val.c_str(), "%d", &condition_param);
				
				entry.condition_param = condition_param;
			}
			else if (att == "skill_id")
			{				
				sscanf(val.c_str(), "%ld", &skill_id);
				
				entry.skill_id = skill_id;
			}
		}
						
		BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "id=\"" << id << "\"\t"
			<< "condition_type=\"" << condition_type << "\"\t"
			<< "condition_param=\"" << condition_param << "\"\t"
			<< "skill_id=\"" << skill_id << "\"\t"
			<< "";
		
		const MemSkillEntry* skill_entry = GetSkillEntry(entry.skill_id);
		if (!skill_entry)
		{
			BOOST_LOG_TRIVIAL(error) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
				<< "Load skill_entry failed for entry: " << entry.id << " skill_id: " << entry.skill_id;
				
			return false;
		}
		
		entry.skill_entry = skill_entry;
		
		passive_skill_entry_map_[id] = entry;
	}
	
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "total num = " << passive_skill_entry_map_.size();

	return ret;
}


//-----------------------------------------------------------------------------
// 获得各资源项属性
//-----------------------------------------------------------------------------
const MemSkillEntry* ResMgr::GetSkillEntry(const int64_t id) const
{
	std::map<int64_t, MemSkillEntry>::const_iterator iter;
	std::map<int64_t, MemSkillEntry>::const_iterator iter_end;	
	
	iter = skill_entry_map_.find(id);
	iter_end = skill_entry_map_.cend();
	
	if (iter != iter_end)
		return &(iter->second);
	
	return NULL;
}

const MemPassiveSkillEntry* ResMgr::GetPassiveSkillEntry(const int64_t id) const
{
	std::map<int64_t, MemPassiveSkillEntry>::const_iterator iter;
	std::map<int64_t, MemPassiveSkillEntry>::const_iterator iter_end;	
	
	iter = passive_skill_entry_map_.find(id);
	iter_end = passive_skill_entry_map_.cend();
	
	if (iter != iter_end)
		return &(iter->second);
	
	return NULL;
}