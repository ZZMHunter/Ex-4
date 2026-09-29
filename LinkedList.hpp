// LinkedList.hpp
// CSCI 235 -- Exercise 4: Linked List Operations
// Provided file -- do not modify. Gradescope compiles your submission
// against the original version of this file.

#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <string>

// A singly linked list of ints: a chain of heap-allocated nodes, each
// holding one value and the address of the next node. head_ points at the
// first node; the last node's next is nullptr; head_ == nullptr is the
// empty list.
class LinkedList {
public:
    LinkedList();      // provided -- head_ = nullptr
    ~LinkedList();     // provided -- deletes every node

    // Copying a LinkedList is out of scope for this exercise, so it is
    // disabled here. (Without a deep copy, two lists would share one chain
    // of nodes and both destructors would delete each node -- the double
    // free from Day 6.) Attempting to copy is a compile error, not a
    // run-time bug, which is exactly what you want.
    LinkedList(const LinkedList& other) = delete;
    LinkedList& operator=(const LinkedList& other) = delete;

    // ---- Implement these five in LinkedList.cpp ----
    void prepend(int value);                // Task A
    void append(int value);                 // Task B
    bool insertAt(int pos, int value);      // Task C
    bool removeValue(int target);           // Task D
    void reverse();                         // Task E

    // Task F (OPTIONAL PRACTICE -- not graded)
    bool removeAt(int pos);

    // ---- Provided observers ----
    bool empty() const;               // head_ == nullptr
    int  size() const;                // O(n): counts the nodes by walking them
    int  getEntry(int pos) const;     // 0-based; throws std::out_of_range
    std::string toString() const;     // "10 -> 20 -> 30", or "(empty)"

private:
    struct Node {
        int   data;
        Node* next;
    };

    Node* head_;
};

#endif
