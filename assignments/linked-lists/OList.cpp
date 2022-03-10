#include <iostream>
#include "OList.h"
//#include "Node.h"
//#include "List.h"

OList::OList() {
	head = nullptr;
	
}

OList::~OList() {
	while( head != nullptr) {
		remove(0);
	}
}

void OList::insert(int value) {
	Node *newNode = new Node(value);
	Node *walker = head;
	Node* trailer = nullptr;

	while(walker != nullptr && walker->getData() <= value) {
		trailer = walker;
		walker = walker -> getNext();
	
	}

	if(trailer == nullptr) {
		newNode->setNext(head);
		head = newNode;
	} else {
		trailer->setNext(newNode);
		newNode->setNext(walker);
	}


}


int OList::get(int loc){
    Node* walker = head;
    int place = 0;
    if (loc<0)
        throw std::out_of_range("Out of range");
    while(walker!=nullptr){
        if (place==loc){
            return walker->getData();
        }
        place++;
        walker=walker->getNext();
    }
    throw std::out_of_range("Out of range");
}

void OList::remove(int loc){
    Node* trailer = nullptr;
    Node* walker = head;
    int place = 0;
    if (loc<0)
        throw std::out_of_range("Out of range");
    while(walker!=nullptr && place!=loc){
        place++;
        trailer=walker;
        walker=walker->getNext();
    }
    if (walker==nullptr)
        throw std::out_of_range("Out of range");
    if (trailer==nullptr)
        head=walker->getNext();
    else
        trailer->setNext(walker->getNext());
    delete walker;
}

bool OList::contains(int value) {
	if(value < head->getData()) {
		return false;
	}

	Node* walker = head;
	while(walker != nullptr) {
		if(walker->getData() == value) {
			return true;
		}
	
		walker = walker->getNext();
	}

	return false;
}
std::string OList::toString(){
    std::string output = "";
    Node* walker = head;
    while (walker!=nullptr){
        output+=std::to_string(walker->getData());
        walker=walker->getNext();
        output+="-->";
    }
    output+="nullptr";
    return output;
}

void OList::reverse() {
	if(head == nullptr) {
		return;
	}

	Node* trailer = nullptr;
	Node* walker = head;

	if(walker != nullptr) {
		trailer = walker;
		walker = walker->getNext();
		while(walker != nullptr) {
			trailer->setNext(walker->getNext());
			walker->setNext(head);
			head = walker;
			walker = trailer->getNext();
		}


	}

}
