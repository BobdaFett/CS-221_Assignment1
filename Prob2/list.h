// list.h
//
// This file is the specification for a class implementing a linked list of integers.
//

#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class Iterator;

class List {
friend class Iterator;
public:

    List() : first(nullptr), last(nullptr) {}
    ~List();

    /**
     * Insert a value at the front of the list.
     * @param value The value to insert.
     */
    void frontInsert(int value);

    /**
     * Insert value at the end of the list.
     * @param value Value to insert.
     */
    void rearInsert(int value);

    /**
     * Delete the value at the front of the list.
     * @return The new first value of the list.
     */
	int frontDelete();

    /**
     * Delete the value at the end of the list.
     * @return The new last value of the list.
     */
	int rearDelete();

    /// @return The length of the list.
    int length() const;

    /// @returns A new Iterator at the beginning of the list.
    Iterator begin();

    /// @returns A new Iterator at the end of the list.
    Iterator end();

    /**
     * Insert a value at a point specified by an Iterator.
     * @param i The Iterator.
     * @param value The value to insert.
     */
    friend void insert(Iterator i, int value);

    /**
     * Delete a value at a point specified by an Iterator.
     * @param i The Iterator.
     */
    friend void del(Iterator i);

    /**
     * Prints the list.
     * @return An ostream object that contains the information about the List.
     */
    friend ostream& operator<<(ostream& out, List& l);


protected:
    struct Node {
        int data;
        Node *next;
    };

	Node* first;
    Node* last;
};

#endif //LIST_H
