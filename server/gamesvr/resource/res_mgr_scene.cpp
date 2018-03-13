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

bool ResMgr::LoadHeroGroupEntryList()
{
	bool ret = true;
	
	hero_group_entry_map_.clear();
	
	pt::ptree tree;
	std::stringstream filename;
	filename << RESOURCE_PATH << HERO_GROUP_ENTRY_FILE;
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "filename = " << filename.str();
	pt::read_xml(filename.str().c_str(), tree);
	const pt::ptree &rows = tree.get_child("rows", empty_ptree());
	BOOST_FOREACH(const pt::ptree::value_type &row, rows)
	{
		const pt::ptree &attrs = row.second.get_child("<xmlattr>", empty_ptree());
		
		MemHeroGroupEntry entry;
		int64_t id = 0;
		int64_t hero_id_1 = 0, hero_id_2 = 0, hero_id_3 = 0;
		int64_t hero_id_4 = 0, hero_id_5 = 0, hero_id_6 = 0;
		int32_t pos_1 = 0, pos_2 = 0, pos_3 = 0;
		int32_t pos_4 = 0, pos_5 = 0, pos_6 = 0;
		
		BOOST_FOREACH(const pt::ptree::value_type &v, attrs)
		{
			std::string att = v.first.data();
			std::string val = v.second.data();
			
			if (att == "id")
			{
				sscanf(val.c_str(), "%ld", &id);
				
				entry.id = id;
			}
			else if (att == "hero_id_1")
			{
				sscanf(val.c_str(), "%ld", &hero_id_1);
				
				entry.hero_id_1 = hero_id_1;
			}
			else if (att == "hero_id_2")
			{
				sscanf(val.c_str(), "%ld", &hero_id_2);
				
				entry.hero_id_2 = hero_id_2;
			}
			else if (att == "hero_id_3")
			{
				sscanf(val.c_str(), "%ld", &hero_id_3);
				
				entry.hero_id_3 = hero_id_3;
			}
			else if (att == "hero_id_4")
			{
				sscanf(val.c_str(), "%ld", &hero_id_4);
				
				entry.hero_id_4 = hero_id_4;
			}
			else if (att == "hero_id_5")
			{
				sscanf(val.c_str(), "%ld", &hero_id_5);
				
				entry.hero_id_5 = hero_id_5;
			}
			else if (att == "hero_id_6")
			{
				sscanf(val.c_str(), "%ld", &hero_id_6);
				
				entry.hero_id_6 = hero_id_6;
			}
			else if (att == "pos_1")
			{
				sscanf(val.c_str(), "%d", &pos_1);
				
				entry.pos_1 = pos_1;
			}
			else if (att == "pos_2")
			{
				sscanf(val.c_str(), "%d", &pos_2);
				
				entry.pos_2 = pos_2;
			}
			else if (att == "pos_3")
			{
				sscanf(val.c_str(), "%d", &pos_3);
				
				entry.pos_3 = pos_3;
			}
			else if (att == "pos_4")
			{
				sscanf(val.c_str(), "%d", &pos_4);
				
				entry.pos_4 = pos_4;
			}
			else if (att == "pos_5")
			{
				sscanf(val.c_str(), "%d", &pos_5);
				
				entry.pos_5 = pos_5;
			}
			else if (att == "pos_6")
			{
				sscanf(val.c_str(), "%d", &pos_6);
				
				entry.pos_6 = pos_6;
			}
		}
			
		BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "id=\"" << id << "\"\t"
			<< "hero_id_1=\"" << hero_id_1 << "\"\t"
			<< "hero_id_2=\"" << hero_id_2 << "\"\t"
			<< "hero_id_3=\"" << hero_id_3 << "\"\t"
			<< "hero_id_4=\"" << hero_id_4 << "\"\t"
			<< "hero_id_5=\"" << hero_id_5 << "\"\t"
			<< "hero_id_6=\"" << hero_id_6 << "\"\t"
			<< "pos_1=\"" << pos_1 << "\"\t"
			<< "pos_2=\"" << pos_2 << "\"\t"
			<< "pos_3=\"" << pos_3 << "\"\t"
			<< "pos_4=\"" << pos_4 << "\"\t"
			<< "pos_5=\"" << pos_5 << "\"\t"
			<< "pos_6=\"" << pos_6 << "\"\t"
			<< "";
		
		const MemHeroEntry* hero_entry_1 = GetHeroEntry(entry.hero_id_1);
		if (hero_entry_1)
		{
			entry.hero_entry_1 = hero_entry_1;
			
			entry.hero_entrys[pos_1] = hero_entry_1;
		}
		
		const MemHeroEntry* hero_entry_2 = GetHeroEntry(entry.hero_id_2);
		if (hero_entry_2)
		{
			entry.hero_entry_2 = hero_entry_2;
			
			entry.hero_entrys[pos_2] = hero_entry_2;
		}
		
		const MemHeroEntry* hero_entry_3 = GetHeroEntry(entry.hero_id_3);
		if (hero_entry_3)
		{
			entry.hero_entry_3 = hero_entry_3;
			
			entry.hero_entrys[pos_3] = hero_entry_3;
		}
		
		const MemHeroEntry* hero_entry_4 = GetHeroEntry(entry.hero_id_4);
		if (hero_entry_4)
		{
			entry.hero_entry_4 = hero_entry_4;
			
			entry.hero_entrys[pos_4] = hero_entry_4;
		}
		
		const MemHeroEntry* hero_entry_5 = GetHeroEntry(entry.hero_id_5);
		if (hero_entry_5)
		{
			entry.hero_entry_5 = hero_entry_5;
			
			entry.hero_entrys[pos_5] = hero_entry_5;
		}
		
		const MemHeroEntry* hero_entry_6 = GetHeroEntry(entry.hero_id_6);
		if (hero_entry_6)
		{
			entry.hero_entry_6 = hero_entry_6;
			
			entry.hero_entrys[pos_6] = hero_entry_6;
		}
		
		hero_group_entry_map_[id] = entry;
	}
	
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "total num = " << hero_group_entry_map_.size();
	
	return ret;
}

bool ResMgr::LoadSceneEntryList()
{
	bool ret = true;
	
	scene_entry_map_.clear();
	
	pt::ptree tree;
	std::stringstream filename;
	filename << RESOURCE_PATH << SCENE_ENTRY_FILE;
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "filename = " << filename.str();
	pt::read_xml(filename.str().c_str(), tree);
	const pt::ptree &rows = tree.get_child("rows", empty_ptree());
	BOOST_FOREACH(const pt::ptree::value_type &row, rows)
	{
		const pt::ptree &attrs = row.second.get_child("<xmlattr>", empty_ptree());
		
		MemSceneEntry entry;
		int64_t id				= 0;
		int32_t type			= 0;
		int64_t hero_group_id	= 0;
		
		BOOST_FOREACH(const pt::ptree::value_type &v, attrs)
		{
			std::string att = v.first.data();
			std::string val = v.second.data();
			
			if (att == "id")
			{
				sscanf(val.c_str(), "%ld", &id);
				
				entry.id = id;
			}
			else if (att == "type")
			{
				sscanf(val.c_str(), "%d", &type);
				
				entry.type = type;
			}
			else if (att == "hero_group_id")
			{
				sscanf(val.c_str(), "%ld", &hero_group_id);
				
				entry.hero_group_id = hero_group_id;
			}
		}
		
		BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
			<< "id=\"" << id << "\"\t"
			<< "type=\"" << type << "\"\t"
			<< "hero_group_id=\"" << hero_group_id << "\"\t"
			<< "";
		
		const MemHeroGroupEntry* hero_group_entry = GetHeroGroupEntry(entry.hero_group_id);
		if (hero_group_entry)
			entry.hero_group_entry = hero_group_entry;
		
		scene_entry_map_[id] = entry;
	}
	
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "total num = " << scene_entry_map_.size();

	return ret;
}


//-----------------------------------------------------------------------------
// 获得各资源项属性
//-----------------------------------------------------------------------------
const MemHeroGroupEntry* ResMgr::GetHeroGroupEntry(const int64_t id) const
{
	std::map<int64_t, MemHeroGroupEntry>::const_iterator iter;
	std::map<int64_t, MemHeroGroupEntry>::const_iterator iter_end;	
	
	iter = hero_group_entry_map_.find(id);
	iter_end = hero_group_entry_map_.cend();
	
	if (iter != iter_end)
		return &(iter->second);
	
	return NULL;
}

const MemSceneEntry* ResMgr::GetSceneEntry(const int64_t id) const
{
	std::map<int64_t, MemSceneEntry>::const_iterator iter;
	std::map<int64_t, MemSceneEntry>::const_iterator iter_end;	
	
	iter = scene_entry_map_.find(id);
	iter_end = scene_entry_map_.cend();
	
	if (iter != iter_end)
		return &(iter->second);
	
	return NULL;
}
