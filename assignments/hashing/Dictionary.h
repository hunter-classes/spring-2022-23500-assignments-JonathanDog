#pragma once
#include "List.h"

class Dictionary {
	private: 
		List* arr[10];
	public:
		Dictionary();
		~Dictionary();
		int hashFunc(std::string name);
		void insert(Person *p);
		Person* retrieve(std::string name);
		std::string getKeys();

};
