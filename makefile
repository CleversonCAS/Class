main:	main.o imp.o 
	g++	 main.o imp.o 

main.o: main.cpp
	g++  -c main.cpp -std=c++11

imp.o: imp.cpp 
	g++	-c imp.cpp -std=c++11

fun.o: fun.h 
	g++ -c fun.h -std=c++11

clean:
	rm *.o
