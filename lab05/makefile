CC=g++
CPPFLAGS = -std=c++11 -I. -g
DEPS = table.h
OBJ = table.o supplied.o main.o 

%.o: %c $(DEPS)
	$(CC) $(CPPFLAGS) -c -o $@ 

main: $(OBJ)
	$(CC) $(CPPFLAGS) -o $@ $^


