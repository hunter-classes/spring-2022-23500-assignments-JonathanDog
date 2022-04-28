#pragma once
#include <iostream>
#include "Node.h"

#define QUEUE_ERR_EMPTY 1
#define QUEUE_ERR_FULL 2
#define QUEUE_ERR_OTHER 4

class Queue
{
	private:
		int arr[7];
		int head, tail;
		bool full;

	public:
		Queue();
		void enqueue(int d);
		int dequeue();
		int front();
		bool is_empty();
		bool is_full();
		std::string print();

};
