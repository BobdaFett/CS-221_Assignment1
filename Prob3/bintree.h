#pragma once;
#include <iostream>
#include <string>
#include "treeNode.h"
using namespace std;

class BinarySearchTree {
public:
   BinarySearchTree();
   void insert(string data);
   void erase(const string& data);
   int count(string data) const;
   void print() const;

   /**
    * Print all TreeNodes at the specified level of the tree.
    * @param level The level to print at.
    */
   void printLevel(int level);
   void printLevel(int level, TreeNode* node);
private:
   TreeNode* root;
};
