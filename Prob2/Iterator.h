//
// Created by lvas4 on 10/29/2022.
//



#ifndef CS_221_ASSIGNMENT1_ITERATOR_H
#define CS_221_ASSIGNMENT1_ITERATOR_H

#include "list.h"

class Iterator {
public:
    Iterator(List::Node *current, List::Node *previous);

    /// @returns A pointer to the current Node object.
    List::Node* get();

    /// Moves iterator to the next linked Node object.
    void next();

    /// Moves iterator to the previous linked Node object.
    void prev();

    /**
     * Determines if two Nodes are equivalent.
     * @returns True if the Nodes are the same.
     */
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
