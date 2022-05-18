#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Dictionary.h"

Person* p1 = new Person("John", "Doe", 22);
Person* p2 =  new Person("Adam", "Smith", 8);
Person* p3 = new Person("Anthony", "Apple", 10);
Person* p4 = new Person("Jonny", "Seed", 102);
Person* p5 = new Person("Mat", "Gay", 2);
Dictionary* dictionary = new Dictionary();


TEST_CASE("Hash function"){
    CHECK(dictionary->hashFunc(p1->get_name())==5);
    CHECK(dictionary->hashFunc(p2->get_name())==4);
    CHECK(dictionary->hashFunc(p3->get_name())==1);
    CHECK(dictionary->hashFunc(p4->get_name())==7);
    CHECK(dictionary->hashFunc(p5->get_name())==5);
    
}

TEST_CASE("insert and Retrieve"){
    dictionary->insert(p1);
    dictionary->insert(p2);
    dictionary->insert(p3);
    dictionary->insert(p4);
    dictionary->insert(p5);
    
    CHECK(dictionary->retrieve("Doe, John") == p1);
    CHECK(dictionary->retrieve("Smith, Adam") == p2);
    CHECK(dictionary->retrieve("Apple, Anthony") == p3);
    CHECK(dictionary->retrieve("Seed, Jonny") == p4);
    CHECK(dictionary->retrieve("Gay, Mat") == p5);
    CHECK(dictionary->retrieve("Gayasd, Mat") == nullptr);
    CHECK(dictionary->retrieve("Gay, Maiasdt") == nullptr);
    CHECK(dictionary->retrieve("Gay, Mi21asfat") == nullptr);
    CHECK(dictionary->retrieve("Gay, Masnfsalkfnat") == nullptr);
	

}
TEST_CASE("allKeys") {
	CHECK(dictionary->getKeys() == "List 0: nullptr\nList 1: Apple, Anthony-->nullptr\nList 2: nullptr\nList 3: nullptr\nList 4: Smith, Adam-->nullptr\nList 5: Gay, Mat-->Doe, John-->nullptr\nList 6: nullptr\nList 7: Seed, Jonny-->nullptr\nList 8: nullptr\nList 9: nullptr\n");


}

