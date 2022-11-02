//
// Created by lvas4 on 11/1/2022.
//

#include "derivedAction.h"

void DerivedAction::act(TreeNode* node) {
    TreeNode* biggest = largestString(node);
    cout << biggest->data << endl;
    cout << findLength(biggest) << endl;
}

TreeNode* DerivedAction::largestString(TreeNode *current) {
    if (current->left != nullptr) {
        if(findLength(current->left) > findLength(current->right))
            largestString(current->left);
    }
    if (current->right != nullptr) {
        if (findLength(current->right) > findLength(current->left))
            largestString(current->right);
    }
    return current;
}

int DerivedAction::findLength(TreeNode* current) {
    int totalLength = current->data.length();
    if (current->left != nullptr)
        totalLength += current->left->data.length();
    if (current->right != nullptr)
        totalLength += current->right->data.length();
    return totalLength;
}