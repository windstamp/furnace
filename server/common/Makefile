###########################################################
# Makefile for common
###########################################################

include ../Makefile.global

program = main

sources = main.cpp configure.cpp string_tool.cpp \
		event/event_mgr.cpp \
		time/time_tool.cpp time/time_mgr.cpp log/log.cpp network/network.cpp \
		loader/config_mgr.cpp loader/config_mgr_network.cpp \
		loader/const_mgr.cpp loader/const_mgr_param.cpp \
		md5/md5.cpp \
		test/test_event.cpp test/test_loader.cpp test/test_time.cpp test/test_md5.cpp

include_dirs = -I. -I/home/smb/renshi/boost/boost_1_64_0

$(program) : $(sources:.cpp=.o)
	-$(CXX) $(CXXFLAGS) -o $(program) $(sources:.cpp=.o) -lpthread -lboost_log
	
$(sources:.cpp=.d): %.d: %.cpp
	@set -e; rm -f $@; \
	$(CXX) -MM $(CXXFLAGS) $< > $@; \
	echo "	$(CXX) $(CXXFLAGS) -c $<" >> $@; \
	sed 's,/($*/)/.o[ :]*,/1.o $@ : ,g' < $@ > $@; \
	rm -f $@

-include $(sources:.cpp=.d)

libcommon.a : $(sources:.cpp=.o)
	ar -crv libcommon.a $?

.PHONY : release
release : libcommon.a
	rm -rf ../lib
	rm -rf ../include
	rm -rf ../include/define
	rm -rf ../include/loader
	rm -rf ../include/network
	rm -rf ../include/time
	rm -rf ../include/event
	rm -rf ../include/md5
	mkdir -p ../lib
	mkdir -p ../include
	mkdir -p ../include/define
	mkdir -p ../include/loader
	mkdir -p ../include/network
	mkdir -p ../include/time
	mkdir -p ../include/event
	mkdir -p ../include/md5
	cp libcommon.a ../lib
	cp -R *.h ../include
	cp -R define/*.h ../include/define
	cp -R loader/*.h ../include/loader
	cp -R network/*.h ../include/network
	cp -R time/*.h ../include/time
	cp -R event/*.h ../include/event
	cp -R md5/*.h ../include/md5

.PHONY : clean
clean :
	-rm -f ${program}
	-rm -rf libcommon.a	
	-rm -rf $(sources:.cpp=.d)
	-rm -rf $(sources:.cpp=.o)
