#pragma once
#include "Node.h"

class List {
    private:
        Node *head;

    public:
        List();
        ~List();
        Person* locate(int index);
        void insert(Person* data);
        void insert(Person* data, int index);
        std::string toString();
        void remove(int index);
	Person* findByName(std::string name);
};
