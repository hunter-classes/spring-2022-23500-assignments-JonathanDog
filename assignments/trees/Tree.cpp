#include "Tree.h"
#include "Node.h"
#include <iostream>

Tree::Tree() {
        root = nullptr;
}

void Tree::insert(int value) {
        Node *newnode = new Node(value);
    Node *p = root;
    Node *trailer;

    while(p != nullptr) {
        trailer = p;
        if(p->getData() == value) {
            return;
        }
        if(p->getData() < value) {
            p = p->getRight();
        }
        else {
            p = p->getLeft();
        }
    }
    //handle the special case of the tree being empty(null)
    if(root == nullptr) {
        root = newnode;
    }
    else {
        if(trailer->getData() < value) {
            trailer->setRight(newnode);
        }
        else {
            trailer->setLeft(newnode);
        }
    }
}

std::string Tree::traverse (Node *n) {
        if(n == nullptr) {
                return "";
        } else {
                return std::to_string(n->getData()) +  " " + traverse(n->getLeft()) + traverse(n->getRight());

        }
}

std::string Tree::get_debug_string() {
        return traverse(root);
}

void Tree::setup() {
        Node *n = new Node(8);
        root = n;
        n =  new Node(3);
        root->setLeft(n);
        n = new Node(10);
        root->setRight(n);
        n = new Node(1);
        root->getLeft()->setLeft(n);
	n = new Node(6);
	root->getLeft()->setRight(n);
	n = new Node(4);
	root ->getLeft()->getRight()->setLeft(n);
	n = new Node(7);
	root->getLeft()->getRight()->setRight(n);
	n = new Node(14);
	root->getRight()->setRight(n);
}

int Tree::search(int value){
  Node *t = root;

  while (t != nullptr){
    int tval = t->getData();
    if (tval==value){
      return value;
    }

    if (tval < value){
      t = t->getRight();
    } else {
      t = t->getLeft();
    }
    
  }


  throw 1; 
  
}

int Tree::searchr(int value, Node *n){
  if (n==nullptr){
    throw 1;
  }

  int x = n->getData();
  if (x==value){
    return value;
  } else if (x>value){
    return searchr(value,n->getLeft());
  } else {
    return searchr(value,n->getRight());
  }
}

int Tree::searchr(int value){
  return searchr(value,root);
}

void Tree::insertr(int value){
    if (root==nullptr){
        Node *newnode = new Node(value);
        root = newnode;
    }
    else
        insertr(value,root);
}
void Tree::insertr(int value, Node *r){
    Node *newnode = new Node(value);
    if (r->getData()>=value){
        if (r->getLeft()==nullptr)
            r->setLeft(newnode);
        else
            insertr(value,r->getLeft());
    }else{
        if (r->getRight()==nullptr)
            r->setRight(newnode);
        else {
            insertr(value,r->getRight());
    	}
    }
}

void Tree::remove(int key){
    Node *previous = nullptr, *current = root;
   
    while(current != nullptr and current->getData() != key){
        previous = current;
        if(current->getData() > key) current = current->getLeft();
        else if(current->getData() < key) current = current->getRight();
    } if(current == nullptr) throw std::out_of_range("key not found");
    int c = current->getData();
    Node *l = current->getLeft(), *r = current->getRight();
    if(l == nullptr and r == nullptr){
        if(current == root) delete root, root = nullptr;
        else{ 
            if(c > previous->getData()) previous->setRight(nullptr);
            else if(c < previous->getData()) previous->setLeft(nullptr);
            delete current, current = nullptr; 
        } return;
    }
    if(l == nullptr or r == nullptr){
        if(current == root) root = l == nullptr ? r : l;
        else{ Node* next = l == nullptr ? r : l; 
            if(c > previous->getData()) previous->setRight(next);
            else if(c < previous->getData()) previous->setLeft(next); 
        } delete current, current = nullptr; return;
    }
    Node *successor = r;
    while(successor->getLeft() != nullptr) successor = successor->getLeft();
    int temp = successor->getData();
    remove(temp); current->setData(temp);
}

int Tree::numLeaves() {
	return countLeaves(root);
}

int Tree::countLeaves(Node *n) {
	if(n == nullptr) {
		return 0;
	} else {
		if(n->getLeft() == nullptr && n->getRight() == nullptr) {
			return 1;
		}

		return countLeaves(n->getLeft()) + countLeaves(n->getRight());

	}

}

int Tree::height() {
	return height(root);

}

int Tree::height(Node *n) {
	if(n == nullptr) {
		return 0;
	} 
	int left = height(n->getLeft());
	int right = height(n->getRight());

	return std::max(left, right) + 1;


}

bool Tree::cousins(int a, int b) {
	int lv1 = 0;
	int lv2 = 0;

	Node *w = root;
	while( w != nullptr) {
		int val = w->getData();
		if(val == a) {
			break;
		}

		else if(val < a) {
			lv1++;
			w = w->getRight();
		}

		else {
			lv1++;
			w = w->getLeft();
		}
	
	}

	w = root;
	while( w != nullptr) {
                int val = w->getData();
                if(val == b) {
                        break;
                }

                else if(val < b) {
                        lv2++;
                        w = w->getRight();
                }

                else {
                        lv2++;
                        w = w->getLeft();
                }

        }

	return lv1 == lv2;
}

int Tree::treesum(Node *n){
  if (n==nullptr){
    return 0;
  } else {
    return n->getData() +
      treesum(n->getLeft()) +
      treesum(n->getRight());
  }
}

int Tree::treesum(){
  return treesum(root);
}
