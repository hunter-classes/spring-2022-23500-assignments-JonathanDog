#include <iostream>
#include "List.h"

List::List() {
    head = nullptr;
}

List::~List() {
	Node *trailer;
        std::cerr << "Destructing\n";	
 	while(head != nullptr) {
		trailer = head;
		head = head->getNext();
		delete trailer;
	}	
 
}

void List::insert(int data) {
    
    Node *tmp = new Node(data);

    
    tmp->setNext(head);
    this->head = tmp;
}

std::string List::toString() {
    
    Node *walker = head;
    std::string s  = "";
    while(walker != nullptr) {
        s = s + std::to_string(walker->getData()) + "-->";
        walker = walker->getNext();
    }
    s += "nullptr";
    return s;
}

int List::locate(int index) {
    Node *walker = head;

    int counter = 0;
    while(walker != nullptr && counter < index) {
        walker = walker->getNext();
        counter++;
    }
    if(walker) {
 	    
    	return walker->getData();
    } else {
	return -1;
    }
}

void List::insert(int data, int index) {
    Node *tmp = new Node(data);
    Node *walker = head;
    Node *trailer = nullptr;
    
   
    while(walker != nullptr && index > 0) {
	trailer = walker;
        walker = walker->getNext();
       	index--;
    }

    if ( index > 0) {
	throw std::out_of_range("Out of range");
    }

    if(trailer==nullptr) {
	tmp->setNext(head);
	head=tmp;
    } else {

    	trailer->setNext(tmp); 
    	tmp->setNext(walker);
    }
}

void List::remove(int index) {
    if(index == 0 && head != nullptr) {
	Node* newhead = head->getNext();
	delete head;
	head = newhead;
    }    


    Node *walker = head;
    Node *temp;

    int counter = 0;
    while(walker != nullptr) {
        if(counter == index-1) {
            temp = walker->getNext();
            walker->setNext(walker->getNext()->getNext());
            break;
        }
        walker = walker->getNext();
        counter++;
    }
    delete temp;
}
