OBJS	= process.o datalogger.o linkedlist.o surveyData.o
SOURCE	= process.cpp datalogger.cpp linkedlist.cpp surveyData.cpp
HEADER	= datalogger.h linkedlist.h surveyData.h
OUT	= process
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

surveyData.o: surveyData.cpp
	$(CC) $(FLAGS) surveyData.cpp


clean:
	rm -f $(OBJS) $(OUT)
