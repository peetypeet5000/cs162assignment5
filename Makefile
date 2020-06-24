CC = g++ -std=c++11 -g -Wall
exe_file = linked_list
$(exe_file):  prog.o list.o node.o util.o
	$(CC) prog.o list.o node.o util.o -o $(exe_file)
prog.o: prog.cpp
	$(CC) -c prog.cpp
list.o: list.cpp
	$(CC) -c list.cpp
node.o: node.cpp
	$(CC) -c node.cpp
util.o: util.cpp
	$(CC) -c util.cpp

clean:
	rm *.o $(exe_file)

tar:
	tar -cvf $(exe_file).tar *.cpp *.h readme.txt Makefile
