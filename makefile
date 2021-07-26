main: main.cpp btree_map.h btree.h die.h
	g++ -std=c++11 main.cpp -o main -O3 -fno-elide-constructors

clean:
	rm -f main
