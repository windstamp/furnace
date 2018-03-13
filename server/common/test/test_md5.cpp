// boost library
#include <boost/log/trivial.hpp>
namespace logging = boost::log;

#include "md5/md5.h"

#include "test/test_md5.h"

void printMD5(const string& message) {
	BOOST_LOG_TRIVIAL(debug) << __FILE__ << ":" << __LINE__ << " | " << __FUNCTION__ << " | "
		<< "md5(\"" << message << "\") = "
       << MD5(message).toStr();
}

void test_md5()
{
	printMD5("");
	printMD5("a");
	printMD5("abc");
	printMD5("message digest");
	printMD5("abcdefghijklmnopqrstuvwxyz");
	printMD5("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

	return;
}
