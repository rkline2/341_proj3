CXX = g++
CXXFLAGS = -Wall

compile: driver.out

driver.out: HashedSplays.o Node.o Util.o driver.o testdriver.o
	$(CXX) $(CXXFLAGS) HashedSplays.o Node.o Util.o driver.o testdriver.o -o driver.out

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
	rm -rf *.o
	rm -f *.out
	rm -f *~

run:
	./driver.out $(DATA)

val:
	valgrind --tool=memcheck --leak-check=full --show-reachable=yes ./driver.out $(DATA)
