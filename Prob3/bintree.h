#pragma once;
#include <iostream>
#include <string>
#include "treeNode.h"
#include "action.h"
#include "derivedAction.h"

using namespace std;

class BinarySearchTree {
public:
   BinarySearchTree();

   /**
    * Inserts a Node in the proper place in the binary tree.
    * @param data The data to insert.
    */
   void insert(string data);

   /**
    * Finds and erases data in the binary tree.
    * @param data The data to erase.
    */
   void erase(const string& data);

   /**
    * I honestly have no idea what this does.
    * @param data It's data.
    * @return Something.
    */
   int count(string data) const;

   /**
    * Prints the entire binary tree in order.
    */
   void print() const;

   /**
    * Print all TreeNodes at the specified level of the tree.
    * @param level The level to print at.
    */
   void printLevel(int level);

   /**
    * Carries out a postorder action other than printing the binary tree.
    * @param a The Action to be carried out.
    */
   void postorder(DerivedAction* a);

private:
    /// This is private and only for use from the public version of printLevel. Allows recursion for printing.
    void printLevel(int level, TreeNode* node);
    TreeNode* root;
};
