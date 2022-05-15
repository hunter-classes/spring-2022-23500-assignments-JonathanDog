#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <iostream>
#include "doctest.h"
#include "Tree.h"

TEST_CASE("searchr") {
	Tree *t = new Tree();
	try{
		int val = t->searchr(10);
		CHECK(val == 10);
	} catch (int e) {

		CHECK(e == 1);
	}

	t->setup();
	CHECK(t->searchr(8) == 8);
	CHECK(t->searchr(3) == 3);
	CHECK(t->searchr(6) == 6);
	CHECK(t->searchr(4) == 4);

	try {
		int val = t->searchr(11);
		
	} catch (int e) {
		CHECK(e == 1);
	}

	try {
                int val = t->searchr(100);

        } catch (int e) {
                CHECK(e == 1);
        }
	
	try {
                int val = t->searchr(101);

        } catch (int e) {
                CHECK(e == 1);
        }

}

TEST_CASE("rinsert") {
	Tree *t = new Tree();

	t->setup();
	t->insertr(102);
	CHECK(t->searchr(102) == 102);

	t->insertr(103);
        CHECK(t->searchr(103) == 103);

	t->insertr(101);
        CHECK(t->searchr(101) == 101);
	

}

TEST_CASE("remove") {
	Tree *t = new Tree();
	t->setup();
	//std::cout << t->get_debug_string() << std::endl;

	CHECK(t->searchr(3) == 3);
	
	t->remove(3);
	//std::cout << t->get_debug_string();

	try{
		t->searchr(3);	

	} catch(int e) {
		CHECK(e == 1);
	}

	t->remove(10);

        try{
                t->searchr(10);

        } catch(int e) {
                CHECK(e == 1);
        }
	
	t->remove(6);

        try{
                t->searchr(6);

        } catch(int e) {
                CHECK(e == 1);
        }
	
//	std::cout << t->get_debug_string();
	
	CHECK(t->get_debug_string() == "8 4 1 7 14 ");



}

TEST_CASE("height") {
	Tree *t = new Tree();
	t->setup();

	
	t->insertr(13);
	CHECK(t->height() == 4);
	t->insertr(12);
	CHECK(t->height() == 5);

	t->insertr(101);
	t->insertr(102);
	t->insertr(103);
	CHECK(t->height() == 6);

}

TEST_CASE("numLeaves") {
	Tree *t = new Tree();
	t->setup();

	CHECK(t->numLeaves() == 4);
	t->insert(13);
	t->insert(16);

	CHECK(t->numLeaves() == 5);

	t  = new Tree();
	t->insert(8);
	t->insert(10);
	t->insert(5);
	
	CHECK(t->numLeaves() == 2);
	
	t->insert(9);
	t->insert(11);

	CHECK(t->numLeaves() == 3);
}

TEST_CASE("cousins?") {
	Tree *t = new Tree();

	t->setup();

	CHECK(t->cousins(3,10));
	CHECK(!t->cousins(3,6));
	CHECK(t->cousins(6,14));
	CHECK(!t->cousins(4,10));
	CHECK(t->cousins(4,7));




}
