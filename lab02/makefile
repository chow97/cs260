CC=g++
CPPFLAGS = -std=c++11 -I. -g
DEPS = dlist.h
OBJ = dlist.o supplied.o main.o 

%.o: %c $(DEPS)
	$(CC) $(CPPFLAGS) -c -o $@ 

main: $(OBJ)
	$(CC) $(CPPFLAGS) -o $@ $^


