###########################################################
# Makefile for gamesvr
###########################################################

include ../Makefile.global

program = gamesvr

sources = server.cpp \
		container/hero_container.cpp \
		event/async_event_handle_func.cpp event/sync_event_handle_func.cpp \
		fight/fightable.cpp fight/fight_hero.cpp fight/fight_group.cpp fight/fight_helper.cpp \
		fight/fight_util_object.cpp fight/round.cpp fight/scene.cpp fight/scene_mgr.cpp \
		fight/skill.cpp \
		generator/id_generator.cpp generator/id_generator_hero.cpp \
		generator/id_generator_item.cpp generator/id_generator_player.cpp \
		object/hero.cpp object/object_pool_mgr.cpp \
		param/param_mgr.cpp \
		player/player.cpp player/player_mgr.cpp \
		resource/res_mgr.cpp resource/res_mgr_mission.cpp resource/res_mgr_rank.cpp \
		resource/res_mgr_hero.cpp resource/res_mgr_hero_att.cpp resource/res_mgr_skill.cpp \
		resource/res_mgr_scene.cpp \
		util/util_kit_mgr.cpp
		
include_dirs = -I. -I../ -I../include -I/home/smb/renshi/boost/boost_1_64_0

$(program) : $(sources:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o $(program) $(sources:.cpp=.o) -L../lib -lcommon -lpthread -lboost_log

$(sources:.cpp=.d): %.d: %.cpp
	@set -e; rm -f $@; \
	$(CXX) -MM $(CXXFLAGS) $< > $@; \
	echo "	$(CXX) $(CXXFLAGS) -c $<" >> $@; \
	sed 's,/($*/)/.o[ :]*,/1.o $@ : ,g' < $@ > $@; \
	rm -f $@

-include $(sources:.cpp=.d)

.PHONY : clean
clean :
	-rm -if $(program)
	-rm -if $(sources:.cpp=.d)
	-rm -if $(sources:.cpp=.o)
