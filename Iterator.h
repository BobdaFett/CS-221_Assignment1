//
// Created by lvas4 on 10/29/2022.
//

#ifndef CS_221_ASSIGNMENT1_ITERATOR_H
#define CS_221_ASSIGNMENT1_ITERATOR_H

#include "list.h"

class Iterator {
public:
    // TODO Figure out why this doesn't work.
    Iterator(List::Node *pNode, List::Node *pNode1) : current(pNode), previous(pNode1) {};

    List::Node* get();
    void next();
    void prev();
    bool equals(List::Node a, List::Node b);

    Iterator operator++(int) {
        i.next();
        return *this;
    };
    Iterator operator--(int) {
        i.prev();
        return *this;
    };

protected:
    List::Node *current, *previous;
};


#endif //CS_221_ASSIGNMENT1_ITERATOR_H
