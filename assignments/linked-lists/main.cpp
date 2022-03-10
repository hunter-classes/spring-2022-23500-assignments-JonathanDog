#include <iostream>

#include "Node.h"
#include "List.h"
#include "OList.h"
int main() {
	List *l1 = new List();
	std::cout << "Creating List\n";

	l1->insert(1);
	l1->insert(2);
	l1->insert(3);

	std::cout << "Inserted values 1,2, and 3" << std::endl;
	std::cout << "Printing the list" << std::endl;
	
	std::cout << l1->toString() << std::endl;

	std::cout << "Second element of the list is: " << l1->locate(1) << std::endl;

	std::cout << "Third element of the list is: " << l1->locate(2) << std::endl;

	std::cout << "Removing the second element and printing list" << std::endl;
	l1->remove(1);
	std::cout << l1->toString() << std::endl;

	std::cout << "l1 is being delted" << std::endl;
	delete l1;
	std::cout << "Testing OList" << std::endl;

	OList *OrderedList = new OList();

	OrderedList->insert(10);
	OrderedList->insert(-1);
	OrderedList->insert(5);
	OrderedList->insert(6);

	std::cout << "Inserted 10, -1, 5, 6" << std::endl;
	std::cout << "Printing List: " << OrderedList->toString() << "\n";

	std::cout << std::boolalpha;

	std::cout << "Does OrderedList have 5: " << OrderedList->contains(5) << std::endl;

	std::cout << "Does OrderedList have 20: " << OrderedList -> contains(20) << std::endl;

	std::cout << "Does OrderedList have -1: " << OrderedList -> contains(-1) << std::endl;

	std::cout << "Value of first element: " << OrderedList -> get(0) << std::endl;;

	std::cout << "Value of third element: " << OrderedList -> get(2) << std::endl;

	std::cout << "Removing first element" << std::endl;
	OrderedList -> remove(0);

	std::cout << OrderedList->toString() << std::endl;

	std::cout << "Removing second element" << std::endl;
        OrderedList -> remove(1);

        std::cout << OrderedList->toString() << std::endl;

	OrderedList->reverse();
	std::cout << OrderedList -> toString() << std::endl;

	OrderedList->reverse();
        std::cout << OrderedList -> toString() << std::endl;

	delete OrderedList;
	
	std::cout << "Deleted List" << std::endl;	



}
