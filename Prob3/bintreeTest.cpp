#include <iostream>
#include <string>
#include "bintree.h"
using namespace std;

int main() {
   BinarySearchTree t;
   t.insert("D");
   t.insert("B");
   t.insert("A");
   t.insert("C");
   t.insert("F");
   t.insert("E");
   t.insert("I");
   t.insert("G");
   t.insert("H");
   t.insert("J");
   t.print();
   cout << "Removing A, B, F, D" << endl;
   t.erase("A"); // Removing leaf
   t.erase("B"); // Removing element with one child
   t.erase("F"); // Removing element with two children
   t.erase("D"); // Removing root
   t.print();
   cout << t.count("E") << "\n";
   cout << t.count("F") << "\n";

   int level = 4;
   cout << "Printing level " << level << ": ";
   t.printLevel(level);
   return 0;
}
