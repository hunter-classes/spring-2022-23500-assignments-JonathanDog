#include <iostream>

#include "Node.h"
#include "List.h"

int main() {
	//Node *p1 = new Node();
	//p1 -> setData("hello");

	//Node *p2 = new Node("World");
	
	//p1 -> setNext(p2);

	//std::cout << p1->getData() << "\n";
	//std::cout << p2->getData() << "\n";
	//std::cout << p1->getNext()->getData() << "\n";

	//p2 = new Node("!");

	//p1->getNext()->setNext(p2);

	//std::cout << p1->getData() << "\n";
	//std::cout << p1->getNext()->getData() << "\n";
	//std::cout << p1->getNext()->getNext()->getData() << "\n";

	//Node *walker = p1;
	//std::cout << walker->getData() << "\n";

	//walker = walker -> getNext();
	//std::cout << walker->getData() << "\n";

	//walker = walker->getNext();
	//std::cout << walker->getData() << "\n";
	//return 0;
	
	List *list1 = new List();
    	list1->insert("a");
    	list1->insert("b");
    	list1->insert("c");
    	list1->insert("d");
    	list1->insert("e");
    	std::cout << list1->toString() << std::endl; //e d c b a
	std::cout << "Getting index 0" << std::endl;
	std::cout << list1->locate(0) << std::endl; // e	
    	list1->insert("f", 2);
    	std::cout << list1->toString() << std::endl; //e d f c b a
	std::cout << "Getting index 1" << std::endl;
    	std::cout << list1->locate(1) << std::endl; //d

    	list1->remove(3);
    	std::cout << list1->toString() << std::endl; //e d f c b a
    	list1->~List();
    	std::cout << list1->toString() << std::endl; //nullptr
}
