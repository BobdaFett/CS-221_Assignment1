// list.cpp
//
// This file implements the integer linked list class.
//
#include <cassert>
#include <iostream>
#include "list.h"
#include "Iterator.h"
using namespace std;

// Constructor
List::List () {
   first = nullptr;
   last = nullptr;
}

// Destructor
List::~List () {
    Node *next_node;

    while (first != last) {
        next_node = first->next;
        delete first;
        first = next_node;
    }
    delete last;
}

// Insert at front of list
void List::frontInsert (int value) {
    Node *new_node;

    new_node = new Node;
    if (new_node == nullptr) {
        cout << "Unable to allocate memory. Insertion cancelled." << endl;
        return;
    }
    new_node->data = value;
    new_node->next = first;
    first = new_node;
}

// Insert at rear of list
void List::rearInsert (int value) {
    Node *new_node, *current;

    new_node = new Node;
    if (new_node == nullptr) {
        cout << "Unable to allocate memory. Insertion cancelled." << endl;
        return;
    }
    new_node->data = value;
    new_node->next = nullptr;
    last->next = new_node;
    last = new_node;
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

int List::rearDelete2() {
    assert(last != nullptr);
    Node* temp = last;
    int value = last->data;
    last = last->next;
    delete temp;
    return value;
}

int List::length() const {
	int len = 0;
	Node* current = first;
	while (current != last){
		len++;
		current = current->next;
	}
	return len;
}

Iterator List::begin() {
    return Iterator(first, (Node*) nullptr);
}

Iterator List::end() {
    Node *prev = first;
    while(prev->next != nullptr)
        prev = prev->next;
    // This should work but isn't?
    return Iterator(last, prev);
}

void List::insert(Iterator i, int value) {
    Node* toInsert;
    toInsert->data = value;
    toInsert->next = i.get();

    i++;
    Node* prev = i.get();
    prev->next = toInsert;
    i.next(); // Sets iterator equal to value just inserted.
}

void List::del(Iterator i) {
    Node* toDelete = i.get();
    i--;
    Node* current = i.get();
    current->next = toDelete->next;
    delete toDelete;
}

// Print the list
ostream& operator << (ostream& out, List& l) {
	List::Node* current = l.first;

	while (current != nullptr) {
		out << current->data << ' ';
		current = current->next;
	}
	return out;
}

