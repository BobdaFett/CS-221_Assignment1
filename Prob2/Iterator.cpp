//
// Created by lvas4 on 10/29/2022.
//

#include "Iterator.h"

Iterator::Iterator(List::Node *current, List::Node *previous) : current(current), previous(previous) {}

int Iterator::get() {
    return current->data;
}

void Iterator::next() {
    this->current = current->next;
}

void Iterator::prev() {
    this->current = this->previous;
}

bool Iterator::equals(Iterator a, Iterator b) {
    return (a.current == b.current);
}