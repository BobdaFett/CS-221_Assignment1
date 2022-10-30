#pragma once;
#include <iostream>
#include <string>
#include "treeNode.h"
using namespace std;

class BinarySearchTree {
public:
   BinarySearchTree();
   void insert(string data);
   void erase(string data);
   int count(string data) const;
   void print() const;
private:
   TreeNode* root;
};
