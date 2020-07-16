CXX = g++
CXXFLAGS = -ansi -Wall -g
OBJS = driver.o Node.o HashedSplays.o Util.o

# Comment: This rule is optional
compile: all

# Comment: This links all your object files and generates the executable.
all: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o driver.out

driver.o: driver.cpp 
	$(CXX) $(CXXFLAGS) -c driver.cpp

Node.o: Node.h Node.cpp
	$(CXX) $(CXXFLAGS) -c Node.cpp

HashedSplays.o: HashedSplays.h HashedSplays.cpp SplayTree.h Util.o Exceptions.h
	$(CXX) $(CXXFLAGS) -c HashedSplays.cpp

Util.o: Util.h Util.cpp
	$(CXX) $(CXXFLAGS) -c Util.cpp

# Comment: to test with input1.txt, type 'make run DATA=input1.txt' at the command prompt.
run:
	./driver.out $(DATA)

# Comment: an overly simplistic, but quick way to check overall runtime 
runtime:
	/usr/bin/time -p ./driver.out $(DATA)

val:
	valgrind --leak-check=full ./driver.out $(DATA)

val-verbose:
	valgrind --leak-check=full --show-leak-kinds=all -v ./driver.out $(DATA)

clean:
	rm -rf *.o
	rm -f driver.out
	rm -f *~ *#
	rm -f vgcor*
