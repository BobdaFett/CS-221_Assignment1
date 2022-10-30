//
// Created by lvas4 on 10/29/2022.
//

#include "Iterator.h"

Iterator::Iterator(List::Node *pNode, List::Node *pNode1) : current(pNode), previous(pNode1) {}

/// \return Pointer to the current Node object.
List::Node* Iterator::get() {
    return current;
}

/// Moves iterator to the next linked Node object.
void Iterator::next() {
    this->current = current->next;
}

/// Moves iterator to the previous linked Node object.
void Iterator::prev() {
    this->current = this->previous;
}

/// Determines if two Nodes are equivalent.
/// \return True if the Nodes are the same.
bool Iterator::equals(List::Node a, List::Node b) {
    // Determine if a and b are equivalent
}