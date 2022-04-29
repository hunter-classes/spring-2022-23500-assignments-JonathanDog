#include <iostream>
#include <unistd.h>
#include "Stack.h"
#include "Queue.h"
using std::cout;
using std::endl;
int main()
{	std::cout << std::boolalpha;
	Stack *l = new Stack();
	cout << "Empty stack? " << l->is_empty()  << endl;
	l->push(10);

	cout << "First element pushed: " << l->top() << endl;
	cout<< "Empty stack? " << l->is_empty()  << endl;
	cout << "Popping the stack: " << l->pop() << endl;
	cout << "Empty stack?" << l->is_empty() << endl;
	l->push(5);
	cout << "Top: " << l->top() << endl;
	l->push(8);
	cout << "Top: " << l->top() << endl;
	l->push(22);
	cout << "Top: " << l->top() << endl;
	cout << "Empty stack? " << l->is_empty()  << endl;
	cout << "Removed with pop(): " << l->pop() << endl;
	cout << "Top: " << l->top() << endl;
	cout << "Popping: " << l->pop() << endl;
	cout << "Popping: " << l->pop() << endl;
	cout << "Empty stack? " << l->is_empty() << endl;
	try
	{
		cout << "Attempting Pop: " << l->pop() << endl;
	}
	catch (std::exception e)
	{
		cout << e.what() << endl;
	}
	delete l;

	Queue *q = new Queue();
	
	std::cout << "------------------------------" << std::endl;
	std::cout << "Enqueueing 6 then 7 then 8" << std::endl;
	q->enqueue(6);
	q->enqueue(7);
	q->enqueue(8);
	std::cout << "Queue: " << std::endl;
	cout << q->print() << endl;
	std::cout << "Dequeing two times: " << std::endl;
	cout << q->dequeue() << endl;
	cout << q->dequeue() << endl;
	std::cout << "Queue: " << std::endl;
	cout << q->print() << endl;
	std::cout << "Enqueueing 20 then 30 then 40" << std::endl;
	q->enqueue(20);
	q->enqueue(30);
	q->enqueue(40);
	std::cout << "Queue: " << std::endl;
	cout << q->print() << endl;
	std::cout << "Dequeue" << std::endl;
	cout << q->dequeue() << endl;
	std::cout << "Queue: " << std::endl;
	cout << q->print() << endl;
	q->dequeue();
	q->dequeue();
	q->dequeue();
	cout << "Testing dequeue out of range" << endl;
	try {
		q->dequeue();
	} catch(std::exception e) {
		cout << e.what() << endl;
	}
	
	return 0;
}

