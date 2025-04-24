CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

SRC = SquareMat.cpp
MAIN = Main.cpp
TEST = testSquareMat.cpp

Main: $(SRC) $(MAIN)
	$(CXX) $(CXXFLAGS) -o Main $(SRC) $(MAIN)

test: $(SRC) $(TEST)
	$(CXX) $(CXXFLAGS) -o test $(SRC) $(TEST)

valgrind: Main test
	valgrind --leak-check=full --track-origins=yes ./Main
	valgrind --leak-check=full --track-origins=yes ./test


clean:
	rm -f Main test
