all: point hexcorner

point:
	g++ -std=c++11 -lgtest -I/usr/local/include/gtest -I/Users/lrj/Projects/hexchecks/include/ src/Point.cpp src/gtest_main.cpp test/PointTest.cpp -o bin/pointtest.out
	./bin/pointtest.out

hexcorner:
	g++ -std=c++11 -lgtest -I/usr/local/include/gtest -I/Users/lrj/Projects/hexchecks/include/ src/HexCorner.cpp src/Point.cpp src/gtest_main.cpp test/HexCornerTest.cpp -o bin/cornertest.out
	./bin/cornertest.out


