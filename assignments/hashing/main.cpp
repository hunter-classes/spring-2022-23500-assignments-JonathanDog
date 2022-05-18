#include <iostream>
#include "Dictionary.h"
int main() {

	std::cout << "Creating dictionary" << std::endl;
	Dictionary* dic = new Dictionary();
	Person* p1 = new Person("John", "Doe", 22);
	Person* p2 =  new Person("Adam", "Smith", 8);
	Person* p3 = new Person("Anthony", "Apple", 10);
	Person* p4 = new Person("Jonny", "Seed", 102);
	Person* p5 = new Person("Mat", "Gay", 2);
	
	std::cout << "Inserting 5 person objects to dictionary" << std::endl;
	dic->insert(p1);
	dic->insert(p2);
	dic->insert(p3);
	dic->insert(p4);
	dic->insert(p5);
	
	std::cout << "Current representation of dictionary" << std::endl;
	std::cout << dic->getKeys();
	
	std::cout << "Printing hash values of each Person" << std::endl;
	std::cout << "Name: " + p1->get_name() + "Hash Value: " << dic->hashFunc(p1->get_name()) << std::endl;
	std::cout << "Name: " + p2->get_name() + "Hash Value: " << dic->hashFunc(p2->get_name()) << std::endl;
	std::cout << "Name: " + p3->get_name() + "Hash Value: " << dic->hashFunc(p3->get_name()) << std::endl;
	std::cout << "Name: " + p4->get_name() + "Hash Value: " << dic->hashFunc(p4->get_name()) << std::endl;
	std::cout << "Name: " + p5->get_name() + "Hash Value: " << dic->hashFunc(p5->get_name()) << std::endl;
	
	std::cout << "Address when searching: Doe, John " << dic->retrieve("Doe, John") << std::endl;	
	std::cout << "Name of Address: " << dic->retrieve("Doe, John")->get_name() << std::endl;

	std::cout << "Address when searching: Smith, Adam " << dic->retrieve("Smith, Adam") << std::endl;
        std::cout << "Name of Address: " << dic->retrieve("Smith, Adam")->get_name() << std::endl;

	std::cout << "Address when searching: Apple, Anthony " << dic->retrieve("Apple, Anthony") << std::endl;
        std::cout << "Name of Address: " << dic->retrieve("Apple, Anthony")->get_name() << std::endl;

	std::cout << "Address when searching: Seed, Jonny " << dic->retrieve("Seed, Jonny") << std::endl;
        std::cout << "Name of Address: " << dic->retrieve("Seed, Jonny")->get_name() << std::endl;

	std::cout << "Address when searching: Gay, Mat " << dic->retrieve("Gay, Mat") << std::endl;
        std::cout << "Name of Address: " << dic->retrieve("Gay, Mat")->get_name() << std::endl;

	std::cout << "Attempting to retrieve Donny, Way" << std::endl;
	Person* a = dic->retrieve("Donny, Way");
	if(nullptr == a)
		std::cout << "equals nullptr" << std::endl;
	
	std::cout << "Attempting to retrieve Donny, Way" << std::endl;
        a = dic->retrieve("Donny, Way");
	if(nullptr == a)
                std::cout << "equals nullptr" << std::endl;
	
	std::cout << "Attempting to retrieve Donny, Way" << std::endl;
        a = dic->retrieve("Donny, Way");
	if(nullptr == a)
               std::cout << "equals nullptr" << std::endl;

	
}
