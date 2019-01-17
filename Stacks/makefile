# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CC = g++                        # compiler to use

LINKERFLAG = -lm

SRCS := test6.cpp show6.cpp delimiters.cpp
BINS := test6 postfix delimiters

all: test6 postfix delimiters

test6: test6.o
	@echo "Checking.."
	g++ -lm test6.o -o test6

test6.o: test6.cpp
	@echo "Creating object.."
	g++ -c test6.cpp

postfix: postfix.o
	@echo "Checking.."
	g++ -lm postfix.o -o postfix

postfix.o: postfix.cpp
	@echo "Creating object.."
	g++ -c postfix.cpp

delimiters: delimiters.o
	@echo "Checking"
	g++ -lm delimiters.o -o delimiters

delimiters.o: delimiters.cpp
	@echo "Creating object.."
	g++ -c delimiters.cpp

clean:
	@echo "Cleaning up..."
	rm -rvf test6.o test6
	rm -rvf postfix.o postfix
	rm -rvf delimiters.o delimiters
