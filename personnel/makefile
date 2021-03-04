OBJS	= hash.o person.o extra_personnel.o personmgr.o
SOURCE	= hash.cpp person.cpp extra_personnel.cpp personmgr.cpp
HEADER	= hash.h person.h personmgr.h
OUT	= extra_personnel
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

hash.o: hash.cpp
	$(CC) $(FLAGS) hash.cpp 

person.o: person.cpp
	$(CC) $(FLAGS) person.cpp 

extra_personnel.o: extra_personnel.cpp
	$(CC) $(FLAGS) extra_personnel.cpp 

personmgr.o: personmgr.cpp
	$(CC) $(FLAGS) personmgr.cpp 
	
clean:
	rm -f $(OBJS) $(OUT)