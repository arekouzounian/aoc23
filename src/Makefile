all: day4

day1: day1.cpp
	gcc -g $^ -o $@.out -lstdc++

day2: day2.cpp
	gcc -g $^ -o $@.out -lstdc++

day3: day3-2.cpp
	gcc -g $^ -o $@.out -lstdc++

day4: day4.cpp util.cpp 
	gcc -g $^ -o $@.out -lstdc++

clean: 
	rm -rf *.o *.out