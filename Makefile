build:
	g++ -o sicot -std=c++23 src/main.cpp

test:
	g++ -o temp -std=c++23 test.cpp
	./temp
	rm temp
