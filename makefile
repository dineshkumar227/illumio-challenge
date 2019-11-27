simple_nat : address.o main.o
	g++ address.o main.o -o simple_nat
address.o : address.cpp address.h
	g++ -c address.cpp
main.o : main.cpp
	g++ -c main.cpp
clean :
	rm *.o && rm OUTPUT
