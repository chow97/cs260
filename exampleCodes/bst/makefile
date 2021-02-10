CC=g++
CPPFLAGS = -std=c++11 -I. -g
DEPS = table.h
OBJ = table.o supplied.o main.o 

%.o: %c $(DEPS)
	$(CC) $(CPPFLAGS) -g -c -o $@ 

main: $(OBJ)
	$(CC) $(CPPFLAGS) -g -o $@ $^


