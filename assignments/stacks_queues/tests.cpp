#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>


TEST_CASE("Stack and all its functions") {
	Stack *s = new Stack();
	//check if you can see top when stack is empty
	CHECK(s-> is_empty());
	CHECK_THROWS_AS(s->top(), std::out_of_range);

	s->push(1);
	CHECK(!s->is_empty());
	CHECK(s->top() == 1);

	s->push(2);
	CHECK(s->top() == 2);

	s->push(5);
	CHECK(s->top() == 5);

	CHECK(s->pop() == 5 );
	CHECK(s->top() == 2);

	CHECK(s->pop() == 2);
	CHECK(s->pop() == 1);

	CHECK(s->is_empty());

	CHECK_THROWS_AS(s->top(), std::out_of_range);
	CHECK_THROWS_AS(s->pop(), std::out_of_range);
	delete s;
	

}

TEST_CASE("Queue and all its functions") {
	Queue *q = new Queue();
	CHECK_THROWS_AS(q->dequeue(), std::out_of_range);
	CHECK_THROWS_AS(q->front(), std::out_of_range);

	CHECK(q->is_empty());
        CHECK(!q->is_full());	
	
	q->enqueue(0);
	CHECK(q->front() == 0);

	q->enqueue(1);
	CHECK(q->front() == 0);

	for(int i = 2; i<7; i++) {
		q->enqueue(i);
	}
	CHECK(q->front() == 0);

	CHECK_THROWS_AS(q->enqueue(69), std::out_of_range);
	CHECK(q->is_full());
	CHECK(!q->is_empty());

	for(int i = 0; i<7; i++) {
		CHECK(q->dequeue() == i);
		if(i != 6)
			CHECK(q->front() == i + 1);
	}
	CHECK(q->is_empty());
	CHECK_THROWS_AS(q->dequeue(), std::out_of_range);
	delete q;

}
