CC=gcc

CFLAGS= -Wall -Werror -Wextra

SRC=main.c operation.c parser.c

SRC_DYNAMIC= ./operation/add.c ./operation/diff.c ./operation/mult.c ./operation/divis.c

TARGET=main

all: build

build:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

build_dynamic: build_lib
	$(CC) $(CFLAGS) $(SRC)

build_lib: obj
	$(CC) -shared -o libadd.so add.o
	$(CC) -shared -o libdiff.so diff.o
	$(CC) -shared -o libmult.so mult.o
	$(CC) -shared -o libdivis.so divis.o

obj:
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DYNAMIC)

clean:
	rm -rf $(TARGET) *.out *.o *.so