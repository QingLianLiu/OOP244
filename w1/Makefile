# Makefile for Workshop 1 - GCC Platform
# Makefile
#----------------------------------------------------------
# Platform Variables
# uncomment to select option
OPT=-Wall -std=c++0x
#OPT=-std=c++0x
#----------------------------------------------------------
# Set of Rules
# links the binary components together to form the executable
w1: w1.o checkout.o
	g++ -o w1 w1.o checkout.o
# recompiles w1.cpp if any recent changes have affected it
w1.o: w1.cpp w1.h
	g++ -c $(OPT) w1.cpp
# recompiles checkout.cpp if any recent changes have affected it
checkout.o: checkout.cpp checkout.h
	g++ -c $(OPT) checkout.cpp
# removes intermediate files
clean:
	rm *.o
