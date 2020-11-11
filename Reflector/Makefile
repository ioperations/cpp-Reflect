#!/usr/bin/env make
ccred=$(shell echo "\033[0;31m")
ccgreen=$(shell echo "\033[0;32m")
ccyellow=$(shell echo "\033[0;33m")
ccwhite=$(shell echo "\033[0;37m")

srcs = $(wildcard *.cpp)
target=$(patsubst %.cpp, %.o, $(srcs))

CPPFLAGS=-I.
CPPLDFLAGS=-lgtest -lpthread

all:$(target) default 

default:$(target)
	g++ $^ ${CPPLDFLAGS} -o main

clean:
	@-rm -r main a.out $(target)

.PHONY: clean default all
