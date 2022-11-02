#include <iostream>
#include <string>
#include <queue>
#include "bintree.h"
using namespace std;

BinarySearchTree::BinarySearchTree() {
   root = nullptr;
}

void BinarySearchTree::print() const {
   if (root != nullptr)
      root->print_nodes();
}

void BinarySearchTree::insert(string data) {
   TreeNode* new_node = new TreeNode;
   new_node->data = data;
   new_node->left = nullptr;
   new_node->right = nullptr;
   if (root == nullptr) root = new_node;
   else root->insert_node(new_node);
}

int BinarySearchTree::count(string data) const {
   if (root == nullptr) return 0;
   else if (root->find(data)) return 1;
   else return 0;
}

void BinarySearchTree::erase(const string& data) {
   // Find node to be removed

   TreeNode* to_be_removed = root;
   TreeNode* parent = nullptr;
   bool found = false;
   while (!found && to_be_removed != nullptr) {
      if (to_be_removed->data < data) {
         parent = to_be_removed;
         to_be_removed = to_be_removed->right;
      }
      else if (data < to_be_removed->data) {
         parent = to_be_removed;
         to_be_removed = to_be_removed->left;
      }
      else found = true;
   }

   if (!found) return;

   // to_be_removed contains data

   // If one of the children is empty, use the other

   if (to_be_removed->left == nullptr || to_be_removed->right == nullptr) {
      TreeNode* new_child;
      if (to_be_removed->left == nullptr)
         new_child = to_be_removed->right;
      else 
         new_child = to_be_removed->left;
      
	  if (parent == nullptr) // Found in root
         root = new_child;
      else if (parent->left == to_be_removed)
         parent->left = new_child;
      else 
         parent->right = new_child;
      return;
   }
      
   // Neither subtree is empty
   // Find the smallest element of the right subtree
   TreeNode* smallest_parent = to_be_removed;
   TreeNode* smallest = to_be_removed->right;
   while (smallest->left != nullptr) {
      smallest_parent = smallest;
      smallest = smallest->left;
   }

   // smallest contains the smallest child in right subtree

   // Move contents, unlink child
   to_be_removed->data = smallest->data;
   if (smallest_parent == to_be_removed)
      smallest_parent->right = smallest->right;
   else
      smallest_parent->left = smallest->right;
}

void BinarySearchTree::printLevel(int level) {
    printLevel(level, root);
}

void BinarySearchTree::printLevel(int level, TreeNode* node) {
    if (level == 1) {
        cout << node->data << " ";
    } else {
        if (node->right != nullptr)
            printLevel(level - 1, node->right);
        if (node->left != nullptr)
            printLevel(level - 1, node->left);
    }
}

void BinarySearchTree::postorder(DerivedAction *a) {
    if (root != nullptr) {
        a->act(root->left);
        a->act(root->right);
    }
}