# Author: Muhammad Shamoon Saleem

# compiler to use
CROSS_COMPILE ?= aarch64-none-linux-gnu-gcc
CC = gcc

arg :=
file := write
filename :=
##input:=
##prereq =  
native ?= writer
cross ?= writer

##LINKERFLAG = -lm
##first = $1
##@echo $(first)
Command := $(firstword $(MAKECMDGOALS))
all: NATIVE	
#######################################################################
NATIVE: $(native)
ifneq ($(Command),CROSS_COMPILE)
	@echo $(Command)
$(native):$(native).object  
	@echo "Checking..for native compile"
	gcc -lm $(native).o -o $(native)

$(native).object:$(native).c
	@echo "Creating object..for native compile"
	gcc -c $(native).c
else
	@echo "Not native compilation" 
endif
	
#######################################################################	
.PHONY: clean
clean:
	@echo "Cleaning up..."
	rm -rvf *.o *.elf *.bin *.exe *.ko *.deb *.a writer test #*.txt
	#rm -rvf test.o test
#######################################################################
RUN: run
run: 
	./$(file) "$(filename)" "$(arg)" 

#######################################################################

CROSS_COMPILE: $(cross)
ifeq ($(Command),CROSS_COMPILE)
	##@echo $(Command)
$(cross): $(cross).o
	echo "Checking to cross compile.."
	echo $< -o $@
	$(CROSS_COMPILE) -g -Wall $< -o $@

$(cross).o: $(cross).c
	@echo "Creating object..to cross compile"
	echo $< -o $@
	$(CROSS_COMPILE) -g -Wall -c $< -o $@ -lm
else
	@echo "No cross compilation required" 
endif
