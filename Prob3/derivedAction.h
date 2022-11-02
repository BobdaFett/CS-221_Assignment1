//
// Created by lvas4 on 11/1/2022.
//

#ifndef CS_221_ASSIGNMENT1_DERIVEDACTION_H
#define CS_221_ASSIGNMENT1_DERIVEDACTION_H

#include "action.h"
#include "treeNode.h"

class DerivedAction : Action {
public:
    /**
     * Finds the TreeNode with the largest sum of lengths of the the strings stored in its children Nodes.
     * @param str Allows for recursion.
     */
    void act(TreeNode* node);

private:
    TreeNode* largestString(TreeNode* current);
    int findLength(TreeNode* current);
};


#endif //CS_221_ASSIGNMENT1_DERIVEDACTION_H
