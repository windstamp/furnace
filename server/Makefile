###########################################################
# Makefile for furnace
###########################################################

include Makefile.global

all : gamesvr
.PHONY : all

.PHONY : dbsvr
dbsvr :
	cd dbsvr && $(MAKE)

.PHONY : gamesvr
gamesvr :
	cd gamesvr && $(MAKE)

.PHONY : loginsvr
loginsvr :
	cd loginsvr && $(MAKE)

.PHONY : release
release :
	@echo "@TODO"

.PHONY : clean
clean :	
	# cd dbsvr && make clean
	cd gamesvr && make clean
	# cd loginsvr && make clean
	
