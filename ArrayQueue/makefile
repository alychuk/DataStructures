# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

CC = g++                      # compiler to use

CFLAGS = -Wall -std=c++11

LINKERFLAG = -lm

SRCS := test7.cpp storesim.cpp
BINS := test7 storesim

all: test7 storesim

test7: test7.o
	@echo "Checking.."
	${CC} ${CFLAGS} ${LINKERFLAG} test7.o -o test7

test7.o: test7.cpp
	@echo "Creating object.."
	${CC} ${CFLAGS} -c test7.cpp

storesim: storesim.o
	@echo "Checking.."
	${CC} ${CFLAGS} ${LINKERFLAG} storesim.o -o storesim

storesim.o: storesim.cpp
	@echo "Creating object.."
	${CC} ${CFLAGS} -c storesim.cpp

clean:
	@echo "Cleaning up..."
	rm -rvf test7.o test7
	rm -rvf storesim.o storesim
