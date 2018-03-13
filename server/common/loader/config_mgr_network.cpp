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

#include "config_mgr.h"

namespace pt = boost::property_tree;

//-----------------------------------------------------------------------------
// 加载常量参数
//-----------------------------------------------------------------------------
bool ConfigMgr::LoadConfigNetwork()
{
	bool ret = true;

	config_network.Init();
	
	pt::ptree tree;
	std::stringstream filename;
	filename << CONFIG_PATH << CONFIG_NETWORK_FILE;
	//std::cout << std::endl << "filename = " << filename.str() << std::endl;
	BOOST_LOG_TRIVIAL(debug) << "filename = " << filename.str();
	pt::read_ini(filename.str().c_str(), tree);
	
	config_network.dbsvr.ip = tree.get<std::string>("dbsvr.ip");
	//std::cout << "dbsvr.ip = " << config_network.dbsvr.ip << std::endl;
	BOOST_LOG_TRIVIAL(debug) << "dbsvr.ip = " << config_network.dbsvr.ip;
	config_network.dbsvr.port = tree.get<int>("dbsvr.port");
	std::cout << "dbsvr.port = " << config_network.dbsvr.port << std::endl;
	BOOST_LOG_TRIVIAL(debug) << "dbsvr.port = " << config_network.dbsvr.port;
	
	config_network.gamesvr.ip = tree.get<std::string>("gamesvr.ip");
	std::cout << "gamesvr.ip = " << config_network.gamesvr.ip << std::endl;
	BOOST_LOG_TRIVIAL(debug) << "gamesvr.ip = " << config_network.gamesvr.ip;
	config_network.gamesvr.port = tree.get<int>("gamesvr.port");
	std::cout << "gamesvr.port = " << config_network.gamesvr.port << std::endl;
	BOOST_LOG_TRIVIAL(debug) << "gamesvr.port = " << config_network.gamesvr.port;
	
	config_network.loginsvr.ip = tree.get<std::string>("loginsvr.ip");
	std::cout << "loginsvr.ip = " << config_network.loginsvr.ip << std::endl;
	BOOST_LOG_TRIVIAL(debug) << "loginsvr.ip = " << config_network.loginsvr.ip;
	config_network.loginsvr.port = tree.get<int>("loginsvr.port");
	std::cout << "loginsvr.port = " << config_network.loginsvr.port << std::endl;
	BOOST_LOG_TRIVIAL(debug) << "loginsvr.port = " << config_network.loginsvr.port;
	
	return ret;
}