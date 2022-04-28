main: main.o Stack.o OList.o Node.o Queue.o
	g++ -o main main.o Stack.o OList.o Node.o Queue.o

tests: tests.o Stack.o OList.o Node.o Queue.o
	g++ -o tests tests.o Stack.o OList.o Node.o Queue.o

tests.o: tests.cpp doctest.h
	g++ -c tests.cpp

main.o: main.cpp Stack.h
	g++ -c main.cpp

stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp

queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

OList.o: OList.cpp OList.h
	g++ -c OList.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm -f *.o
