//
// Created by lvas4 on 10/29/2022.
//



#ifndef CS_221_ASSIGNMENT1_ITERATOR_H
#define CS_221_ASSIGNMENT1_ITERATOR_H

#include "list.h"

class Iterator {
public:
    Iterator(List::Node *pNode, List::Node *pNode1);

    List::Node* get();
    void next();
    void prev();
    bool equals(List::Node a, List::Node b);

    int operator++(int) {
        next();
        return current->data;
    };
    int operator--(int) {
        prev();
        return current->data;
    };

protected:
    List::Node *current, *previous;
};


#endif //CS_221_ASSIGNMENT1_ITERATOR_H
