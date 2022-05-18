#include "Dictionary.h"
#include "List.h"

Dictionary::Dictionary() {
	for(int i = 0; i < 10; i++) {
		arr[i] = new List();
	}
}

Dictionary::~Dictionary() {
	for(int i = 0; i < 10; i++)
		delete arr[i];
}

void Dictionary::insert(Person *p) {
	arr[hashFunc(p->get_name())]->insert(p);
}

int Dictionary::hashFunc(std::string name) {
	int len = name.length();
	int sum = 0;

	for(int i = 0; i<len; i++) {
		sum += (int)name[i];
	}

	return sum % 10;

}

std::string Dictionary::getKeys() {
	std::string s = "";

	for(int i = 0; i < 10; i++) {
		s+= "List " + std::to_string(i) + ": " + arr[i]->toString() + "\n";
	}

	return s;

}

Person* Dictionary::retrieve(std::string name) {
	int index = hashFunc(name);
	
	return arr[index]->findByName(name);
		
}
