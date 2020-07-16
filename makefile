CXX = g++
CXXFLAGS = -Wall

compile: proj3

proj3: HashedSplays.o Node.o Util.o driver.o testdriver.o
	$(CXX) $(CXXFLAGS) HashedSplays.o Node.o Util.o driver.o testdriver.o -o proj3

HashedSplays.o: HashedSplays.h HashedSplays.cpp
	$(CXX) $(CXXFLAGS) -c HashedSplays.cpp

Node.o: Node.h Node.cpp
	$(CXX) $(CXXFLAGS) -c Node.cpp

Util.o: Util.h Util.cpp
	$(CXX) $(CXXFLAGS) -c Util.cpp


driver.o: driver.cpp
	$(CXX) $(CXXFLAGS) -c driver.cpp

testdriver.o: testdriver.cpp
	$(CXX) $(CXXFLAGS) -c testdriver.cpp


clean:
	rm proj3 *o *~

run:
	./proj3 $(DATA)

val:
	valgrind --tool=memcheck --leak-check=full --show-reachable=yes ./proj3 $(DATA)
