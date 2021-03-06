#include <iostream>
#include "Node.h"
#include "BSTree.h"

int main() {
	std::cout << "Printing out test tree I modeled from the video" << "\n";
	Node *n = new Node(10);
	std::cout << n->getData() << "\n";
	Node *n2 = new Node(20);
	n->setLeft(n2);
	std::cout << n->getLeft()->getData() << "\n";
	n2 = new Node(50);
	n-> setRight(n2);
	std::cout << n->getRight()->getData() << "\n";

	n2 = new Node(30);
	n->getLeft()->setLeft(n2);
	std::cout << n->getLeft()->getLeft()->getData() << "\n";
	n2 = new Node(40);
	n->getLeft()->getLeft()->setLeft(n2);
	std::cout << n->getLeft()->getLeft()->getLeft()->getData() << "\n";
	n2 = new Node(60);
	n->getRight()->setLeft(n2);
	std::cout << n->getRight()->getLeft()->getData() << "\n";
	n2 = new Node(70);
	n->getRight()->setRight(n2);
	std::cout << n->getRight()->getRight()->getData() << "\n";

	BSTree *t = new BSTree();
	t->setup();
	
	
	std::cout << "Testing debug" << "\n";
	std::cout << t->get_debug_string() << "\n";
	return 0;

}
