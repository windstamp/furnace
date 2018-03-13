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

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

#include "const_mgr.h"

namespace pt = boost::property_tree;

//-----------------------------------------------------------------------------
// 加载常量参数
//-----------------------------------------------------------------------------
bool ConstMgr::LoadConstParam()
{
	bool ret = true;

	const_param.Init();
	
	pt::ptree tree;
	std::stringstream filename;
	filename << CONST_PATH << CONST_PARAM_FILE;
	//std::cout << std::endl << "filename = " << filename.str() << std::endl;
	BOOST_LOG_TRIVIAL(debug) << "filename = " << filename.str();
	pt::read_ini(filename.str().c_str(), tree);
	
	const_param.guild.max_member_num = tree.get<int>("guild.max_member_num");
	//std::cout << "guild.max_member_num = " << const_param.guild.max_member_num << std::endl;
	BOOST_LOG_TRIVIAL(debug) << "guild.max_member_num = " << const_param.guild.max_member_num;
	
	const_param.player.fight_hero_num = tree.get<int>("player.fight_hero_num");
	//std::cout << "player.fight_hero_num = " << const_param.player.fight_hero_num << std::endl;
	BOOST_LOG_TRIVIAL(debug) << "player.fight_hero_num = " << const_param.player.fight_hero_num;
	
	return ret;
}