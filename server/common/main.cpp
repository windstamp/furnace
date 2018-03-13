/************************************************************************/
/* @file:	main.cpp                                                    */
/* @brief:	common库测试器                                              */
/* @author:	Zhang Keliang                                               */
/* @email:	klzhang@fudan.edu.cn                                        */
/* @date:	2017-06-21                                                  */
/* @last:	2017-06-22                                                  */
/*                                                                      */
/*                                                                      */
/************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include <iostream>

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

#include "test/test_event.h"
#include "test/test_loader.h"
#include "test/test_time.h"
#include "test/test_md5.h"

int main(int argc, char **argv)
{
	BOOST_LOG_TRIVIAL(info) << "test for common begin";
	
	{
		test_loader();
	}
	
	{
		test_time();
	}
	
	{
		test_event();
	}
	
	{
		test_md5();
	}
	
	BOOST_LOG_TRIVIAL(info) << "test for common end";
	
	return 0;
}