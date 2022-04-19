#include "BSTree.h"
#include "Node.h"
#include <iostream>

BSTree::BSTree() {
	root = nullptr;
}

void BSTree::insert(int d) {
	std::cout << "asd";
}

std::string debugH(Node *n) {
	if(n == nullptr) {
		return "";
	} else {
		return std::to_string(n->getData()) +  " " + debugH(n->getLeft()) + debugH(n->getRight());
		
	}
}

std::string BSTree::get_debug_string() {
	return debugH(root);
}

void BSTree::setup() {
	Node *n = new Node(10);
	root = n;
	n =  new Node(20);
	root->setLeft(n);
	n = new Node(30);
	root->setRight(n);
	n = new Node(40);
	root->getLeft()->setLeft(n);
}
