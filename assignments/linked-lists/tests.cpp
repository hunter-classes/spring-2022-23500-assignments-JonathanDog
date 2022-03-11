#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "OList.h"

TEST_CASE("get and insert")
{
   OList *olist = new OList();

   olist->insert(1);
   olist->insert(2);
   olist->insert(3);
   olist->insert(4);
   olist->insert(5);
   olist->insert(6);

   CHECK(olist->get(0) == 1);
   CHECK(olist->get(1) == 2);
   CHECK(olist->get(2) == 3);
   CHECK(olist->get(3) == 4);
   CHECK(olist->get(4) == 5);
   CHECK(olist->get(5) == 6);

   CHECK_THROWS_AS(olist->get(-1), std::out_of_range);
   CHECK_THROWS_AS(olist->get(6), std::out_of_range);
}

TEST_CASE("toString")
{
   OList *olist = new OList();

   CHECK(olist->toString() == "nullptr");

   olist->insert(1);
   olist->insert(2);
   olist->insert(3);

   CHECK(olist->toString() == "1-->2-->3-->nullptr");
}

TEST_CASE("contains")
{
   OList *olist = new OList();

   olist->insert(1);
   olist->insert(2);
   olist->insert(3);

   CHECK(olist->contains(5) == false);
   CHECK(olist->contains(1) == true);
   CHECK(olist->contains(2) == true);
   CHECK(olist->contains(3) == true);
}

TEST_CASE("remove")
{
   OList *olist = new OList();

   olist->insert(1);
   olist->insert(2);
   olist->insert(3);

   CHECK_THROWS_AS(olist->remove(-1), std::out_of_range);
   CHECK_THROWS_AS(olist->remove(4), std::out_of_range);

   olist->remove(1);
   CHECK(olist->toString() == "1-->3-->nullptr");


   olist->remove(1);
   CHECK(olist->toString() == "1-->nullptr");

   olist->remove(0);
   CHECK(olist->toString() == "nullptr");
}

TEST_CASE("reverse")
{
   OList *olist = new OList();

   olist->reverse();
   CHECK(olist->toString() == "nullptr");

   olist->insert(1);
   olist->reverse();
   CHECK(olist->toString() == "1-->nullptr");

   olist->insert(1);
   olist->insert(2);
   olist->insert(3);
   olist->insert(4);
   olist->reverse();
   CHECK(olist->toString() == "4-->3-->2-->1-->1-->nullptr");
}
