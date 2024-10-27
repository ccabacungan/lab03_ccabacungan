// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE

#include "intlist.h"

#include <iostream>
using std::cout;

// Copy constructor
IntList::IntList(const IntList& source) {
    first = nullptr;
    if (source.first == nullptr) {
        return;
    }

    first = new Node;
    first->info = source.first->info;
    first->next = nullptr;

    Node* current = source.first->next;
    Node* following = first;

    while (current != nullptr) {
        Node *newNode = new Node;
        newNode->info = current->info;
        newNode->next = nullptr;

        following->next = newNode;
        following = newNode;

        current = current->next;
    }
}

// Destructor deletes all nodes
IntList::~IntList() {
    Node* current = first;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

// Return sum of values in list
int IntList::sum() const {
    Node* current = first;
    int sum = 0;
    while (current != nullptr) {
        sum += current->info;
        current = current->next;
    }
    return sum;
}

// Returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* current = first;
    while (current != nullptr) {
        if (current->info == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

// Returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (first == nullptr) {
        return 0;
    }

    Node* max = first;
    Node* temp = first->next;

    while (temp != nullptr) {
        if (temp->info > max->info) {
            max = temp;
        }
        temp = temp->next;
    }
    return max->info;
}

// Returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (first == nullptr) {
        return 0;
    }
    Node* current = first;
    int total = sum();
    double count = 0;

    while (current != nullptr) {
        count += 1;
        current = current->next;
    }
    double avg = total / count;
    return avg;
}

// Inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    Node* p = new Node;
    p->info = value;
    p->next = first;
    first = p;
}

// Assignment operator should copy the list from the source
// to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source) {
   if (this == &source) {
        return *this; 
    }
    Node* current = first;
    while (current != nullptr) {
        Node* temp = current; 
        current = current->next; 
        delete temp;
    }
    first = nullptr; 

    if (source.first == nullptr) {
        return *this; 
    }

    first = new Node;
    first->info = source.first->info; 
    first->next = nullptr; 

    Node* scurrent = source.first->next; 
    Node* following = first; 
    while (scurrent != nullptr) {
        Node* newNode = new Node; 
        newNode->info = scurrent->info; 
        newNode->next = nullptr; 

        following->next = newNode; 
        following = newNode; 

        scurrent = scurrent->next; 
    }

    return *this; // Return *this to allow chaining
}

// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// Constructor sets up empty list
IntList::IntList() : first(nullptr) { }

// Append value at end of list
void IntList::append(int value) {
    if (first == nullptr) { // Empty list
        first = new Node;
        first->info = value;
        first->next = nullptr;
    } else {
        Node *n = first;
        while (n->next) // Not last node yet
            n = n->next;

        n->next = new Node;
        n->next->info = value;
        n->next->next = nullptr;
    }
}

// Print values enclose in [], separated by spaces
void IntList::print() const {
    Node* n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// Return count of values
int IntList::count() const {
    int result = 0;
    Node* n = first;
    while (n) {
        ++result;
        n = n->next;
    }

    return result;
}
