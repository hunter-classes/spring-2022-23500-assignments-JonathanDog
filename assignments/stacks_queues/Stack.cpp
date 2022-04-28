#include "Stack.h"
#include <iostream>

void Stack::push(int item)
{
	list.insert(item);
	topindex++;
}

int Stack::pop()
{

	if (topindex <= 0)
	{
		throw std::out_of_range("Nothing to pop list is empty");
	}
	int tmp = list.get(topindex - 1);

	list.remove(topindex - 1);
	topindex--;
	return tmp;
}

int Stack::top()
{
	if (topindex <= 0)
	{
		throw std::out_of_range("List empty no top");
	}
	return list.get(topindex - 1);
}

bool Stack::is_empty()
{
	return (list.toString() == "head-->nullptr");
}


