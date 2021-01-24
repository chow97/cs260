OBJS	= process.o datalogger.o linkedlist.o
SOURCE	= process.cpp datalogger.cpp linkedlist.cpp
HEADER	= datalogger.h linkedlist.h
OUT	= try
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

process.o: process.cpp
	$(CC) $(FLAGS) process.cpp 

datalogger.o: datalogger.cpp
	$(CC) $(FLAGS) datalogger.cpp 

linkedlist.o: linkedlist.cpp
	$(CC) $(FLAGS) linkedlist.cpp 


clean:
	rm -f $(OBJS) $(OUT)
