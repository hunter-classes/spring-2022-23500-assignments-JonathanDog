#pragma once
#include <iostream>
#include "Node.h"

class Tree{
        private:
                Node *root;
        public:
                Tree();
                void insert(int d);
                std::string get_debug_string();
		std::string traverse(Node *n);
                void setup();
		int search(int value);
		int searchr(int value, Node *n);
		int searchr(int value);
		int treesum(Node *n);
		int treesum();
		void insertr(int value);
		void insertr(int value, Node*r);
		void remove(int key);

		//count leaves
		int countLeaves(Node *n);
		int numLeaves();
		//height of a tree
		int height();
		int height(Node *n);
		bool cousins(int a, int b);
		//sum at given level
		//tree pretty printer
		//cousins - true if tow nodes at same level
		//
		//

};

