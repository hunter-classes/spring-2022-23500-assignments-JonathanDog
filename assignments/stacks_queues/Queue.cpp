#include <iostream>
#include "Queue.h"


Queue::Queue()
{
	head = 0;
	tail = 0;
	full = false;
}

std::string Queue::print()
{
	std::string result = "";

	for (int i = head; i < tail; i++)
	{
		result += std::to_string(arr[i%7]) + " ";
	}
	return result;
}

void Queue::enqueue(int data)
{
	if (tail - head == 7 || head - tail == 7)
	{
		full = true;
		throw std::out_of_range("Full queue");
	}
	arr[tail%7] = data;
	tail++;

}
int Queue::dequeue()
{
	if (head == tail)
	{
		throw std::out_of_range("Queue empty cannot dequeue");
	}
	int r = front();
	head++;
	full = false;
	return r;
}
int Queue::front()
{
	if (head == tail)
	{
		throw std::out_of_range("Queue empty cannot get front");
	}
	return arr[head % 7];
}
bool Queue::is_empty()
{
	return !full;
}
bool Queue::is_full()
{
	return full;
}
