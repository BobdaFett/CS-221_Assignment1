// list.cpp
//
// This file implements the integer linked list class.
//
#include <cassert>
#include <iostream>
#include "list.h"
#include "Iterator.h"
using namespace std;

List::~List () {
    Node *next_node;

    while (first != last) {
        next_node = first->next;
        delete first;
        first = next_node;
    }
    delete last;
}

void List::frontInsert (int value) {
    Node *new_node;

    new_node = new Node;
    new_node->data = value;
    new_node->next = first;
    first = new_node;
}

void List::rearInsert (int value) {
    Node *new_node;

    new_node = new Node;
    new_node->data = value;
    new_node->next = nullptr;

    if (first == nullptr && last == nullptr) { // If there are no values in the list
        last = new_node;
        first = new_node;
    } else {
        last->next = new_node;
        last = new_node;
    }
}

int List::frontDelete() {
	assert(first != nullptr);
	Node* temp = first;
	int value = first->data;
	first = first->next;
	delete temp;
	return value;
}

int List::rearDelete() {
	assert(first != nullptr);
	int value;
	if (first->next == nullptr) { // there is a single node in the list
		value = first->data;
		delete first;
		first = nullptr;
	} else { // need to traverse the list
		Node* current = first->next;
		Node* previous = first;
		while (current->next != nullptr) {
			previous = current;
			current = current->next;
		}
		value = current->data;
		delete current;
		previous->next = nullptr;
	}
	return value;
}

int List::length() const {
	int len = 0;
	Node* current = first;
	while (current != nullptr){
		len++;
		current = current->next;
	}
	return len;
}

Iterator List::begin() { return {first, nullptr}; }

Iterator List::end() { return {nullptr, last}; }

void insert(Iterator i, int value) {
    List::Node* toInsert = nullptr;
    toInsert->data = value;
    toInsert->next = i.current;
    i.previous = toInsert;
}

void del(Iterator i) {
    List::Node* temp = i.current;
    i.current = i++;
    delete temp;
}

// Print the list
ostream& operator<<(ostream& out, List& l) {
	List::Node* current = l.first;

	while (current != nullptr) {
		out << current->data << ' ';
		current = current->next;
	}
	return out;
}

