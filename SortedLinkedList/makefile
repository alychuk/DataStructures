# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CC = g++                      # compiler to use

CFLAGS = -Wall -std=c++11

LINKERFLAG = -lm

SRCS := test3.cpp
BINS := test3

all: test3

test3: test3.o
	@echo "Checking.."
	${CC} ${CFLAGS} ${LINKERFLAG} test3.o -o test3

test3.o: test3.cpp
	@echo "Creating object.."
	${CC} ${CFLAGS} -c test3.cpp

clean:
	@echo "Cleaning up..."
	rm -rvf test3.o test3
