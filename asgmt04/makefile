OBJS	= box.o bst.o plantermgr.o planters.o
SOURCE	= box.cpp bst.cpp plantermgr.cpp planters.cpp
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

planters.o: planters.cpp
	$(CC) $(FLAGS) planters.cpp 


clean:
	rm -f $(OBJS) $(OUT)
