// list.h
//
// This file is the specification for a class implementing a linked list of integers.
//

#ifndef LIST_H
#define LIST_H

#include <list>
#include <iostream>
#include "Iterator.h"
using namespace std;

class List {
public:
    friend class Iterator;

    List (); // constructor
    ~List (); // destructor
    void frontInsert (int value); // insert at front of list
    void rearInsert (int value);  // insert at rear of list
	int frontDelete();
	int rearDelete();
    int rearDelete2();
    int length() const;

    Iterator begin();
    Iterator end();

    void insert(Iterator i, int value);
    void del(Iterator i);

    friend ostream& operator << (ostream& out, List& l); // print the list


protected:

    struct Node {
        int data;
        Node *next;
    };

	Node* first;
    Node* last;
};

#endif
