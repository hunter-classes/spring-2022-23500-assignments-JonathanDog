#pragma once
#include "OList.h"

class Stack
{
	private:
		OList list;
		int topindex = 0;
	public:
		void push(int d);
		int pop();
		int top();
		bool is_empty();
};
