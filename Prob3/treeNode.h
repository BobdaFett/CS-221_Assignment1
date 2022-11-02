#pragma once;
#include <iostream>
#include <string>

using namespace std;

class TreeNode {
friend class DerivedAction;
public:
   void insert_node(TreeNode* new_node);
   void print_nodes() const;
   bool find(string value) const;
private:
   string data;
   TreeNode* left;
   TreeNode* right;
friend class BinarySearchTree;
};
