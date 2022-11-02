//
// Created by lvas4 on 10/29/2022.
//



#ifndef CS_221_ASSIGNMENT1_ITERATOR_H
#define CS_221_ASSIGNMENT1_ITERATOR_H

#include "list.h"

class Iterator {
public:
    Iterator(List::Node *current, List::Node *previous);

    /// @returns The data within the current node object.
    int get();

    /// Moves iterator to the next linked Node object.
    void next();

    /// Moves iterator to the previous linked Node object.
    void prev();

    /**
     * Determines if two Nodes are equivalent.
     * @returns True if the Nodes are the same.
     */
    bool equals(Iterator a, Iterator b);

    friend void insert(Iterator i, int value);
    friend void del(Iterator i);

    List::Node* operator++(int) {
        next();
        return current;
    };
    List::Node* operator--(int) {
        prev();
        return current;
    };

protected:
    List::Node *current, *previous;
};


#endif //CS_221_ASSIGNMENT1_ITERATOR_H
