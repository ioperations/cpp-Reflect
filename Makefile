#!/usr/bin/env make
ccred=$(shell echo "\033[0;31m")
ccgreen=$(shell echo "\033[0;32m")
ccyellow=$(shell echo "\033[0;33m")
ccwhite=$(shell echo "\033[0;37m")
# $(error ${ccred} error message ${ccwhite})
# $(info ${ccyellow} info message ${ccwhite})


#check if file exists
#ifneq ("$(wildcard  FILENAME)","")
##file exists; use space insted of tab here
#endif 

#use ${LINENO} to locate the error message location



build-and-run:
	make -C ./Reflector && ./Reflector/main

clean:
	make -C ./Reflector clean
