//
// Created by lvas4 on 10/29/2022.
//

#include "Iterator.h"

Iterator::Iterator(List::Node *current, List::Node *previous) : current(current), previous(previous) {}

List::Node* Iterator::get() {
    return current;
}

void Iterator::next() {
    this->current = current->next;
}

void Iterator::prev() {
    this->current = this->previous;
}

bool Iterator::equals(List::Node a, List::Node b) {
    // Determine if a and b are equivalent
}