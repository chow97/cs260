OBJS	= box.o bst.o plantermgr.o test.o
SOURCE	= box.cpp bst.cpp plantermgr.cpp test.cpp
HEADER	= box.h bst.h plantermgr.h
OUT	= main
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

box.o: box.cpp
	$(CC) $(FLAGS) box.cpp 

bst.o: bst.cpp
	$(CC) $(FLAGS) bst.cpp 

plantermgr.o: plantermgr.cpp
	$(CC) $(FLAGS) plantermgr.cpp 

test.o: test.cpp
	$(CC) $(FLAGS) test.cpp 


clean:
	rm -f $(OBJS) $(OUT)
