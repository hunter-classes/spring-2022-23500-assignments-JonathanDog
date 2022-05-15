#include <iostream>
#include "Node.h"
#include "Tree.h"
int main()
{

  Tree *t = new Tree();
  t->setup();

  std::cout <<  t->get_debug_string() << "\n";
  int v = 5;


  try {
    int x  = t->search(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";

  }

  v = 22;
  try {
    int x  = t->searchr(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";

  }
  v = 8;
  try {
    int x  = t-> searchr(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";

  }

  t->insertr(22);
  std::cout <<  t->get_debug_string() << "\n";
  t->insert(3);
  std::cout <<  t->get_debug_string() << "\n";

  v = 126;
  try {
    int x  = t->searchr(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";
  }
  t->insertr(126);
  std::cout <<  t->get_debug_string() << "\n";

  try {
    int x  = t->searchr(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";

  }

  v = 22;
  try {
    int x  = t->searchr(v);
    std::cout << "Found: " << x << "\n";
  } catch (int e){
    std::cout << v << " not found\n";

  }
 
  std::cout << "\n\n\n Remove----------- \n" << '\n';
  
  t = new Tree();
  t->insert(8);
  t->insert(3);
  t->insert(4);
  t->insert(2);
  std::cout <<  t->get_debug_string() << "\n";
  t->remove(4);
  std::cout <<  t->get_debug_string() << "\n";
  t->remove(2);
  std::cout <<  t->get_debug_string() << "\n";

  
  t = new Tree();
  t->insert(8);
  t->insert(3);
  t->insert(9);
  t->insert(4);
  t->insert(2);
  t->insert(1);
  t->insert(12);
  t->insert(10);
  t->insert(13);


  std::cout <<  t->get_debug_string() << "\n";
  t->remove(12);
  std::cout <<  t->get_debug_string() << "\n";

  
  std::cout << "\n countLeaves below --------------\n" << '\n';
  t = new Tree();
  t->setup();
  std::cout <<  t->get_debug_string() << "\n";
  std::cout << "leaves of tree : " << t->numLeaves() << '\n';

  std::cout << "\nHeight----------------------- \n" << '\n';
  std::cout << "height of t: " << t->height() << '\n';
  
  t->insert(2);
  t->insert(5);
  t->insert(100);

  std::cout << "height after inserting 10, 4, 100: " << t->height() << std::endl;
   

  std::cout << "\nCousins-------------------- \n" << '\n';
  if(t->cousins(3,15)) {
    std::cout << "3/15 cousins" << '\n';
  } else {
    std::cout << "3/5 not cousins" << '\n';
  }
  if(t->cousins(5,15)) {
    std::cout << "5/15 cousins" << '\n';
  } else {
    std::cout << "5/15 not cousins" << '\n';
  }
  return 0;
}
