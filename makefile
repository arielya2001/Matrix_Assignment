CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC = SquareMat.cpp
MAIN = Main.cpp
TEST = testSquareMat.cpp

Main: $(SRC) $(MAIN)
	$(CXX) $(CXXFLAGS) -o Main $(SRC) $(MAIN)

test: $(SRC) $(TEST)
	$(CXX) $(CXXFLAGS) -o test_exec $(SRC) $(TEST)

valgrind: Main
	valgrind ./Main

clean:
	rm -f Main test_exec
