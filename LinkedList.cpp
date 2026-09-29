// LinkedList.cpp
// CSCI 235 -- Exercise 4: Linked List Operations
// Complete the TODO sections below and submit this file.

#include "LinkedList.hpp"

#include <stdexcept>
#include <string>

// ==============================================================
// PROVIDED -- you do not need to change anything above the line
// marked "TODO" further down.
// ==============================================================

LinkedList::LinkedList() : head_(nullptr) {
}

LinkedList::~LinkedList() {
    while (head_ != nullptr) {
        Node* toDelete = head_;   // remember the node to free
        head_ = head_->next;      // advance FIRST, while we still can
        delete toDelete;          // now it is safe to free it
    }
}

bool LinkedList::empty() const {
    return head_ == nullptr;
}

// Note: this walks the chain rather than returning a stored counter, so it
// always reports what the pointers actually say. A production list would
// cache the length in a data member and keep it up to date in every
// insert and remove -- one more invariant to maintain.
int LinkedList::size() const {
    int count = 0;
    for (Node* curr = head_; curr != nullptr; curr = curr->next) {
        ++count;
    }
    return count;
}

int LinkedList::getEntry(int pos) const {
    if (pos < 0) {
        throw std::out_of_range("getEntry: position must not be negative");
    }
    Node* curr = head_;
    for (int i = 0; i < pos && curr != nullptr; ++i) {
        curr = curr->next;
    }
    if (curr == nullptr) {
        throw std::out_of_range("getEntry: position past the end of the list");
    }
    return curr->data;
}

std::string LinkedList::toString() const {
    if (head_ == nullptr) {
        return "(empty)";
    }
    std::string out;
    for (Node* curr = head_; curr != nullptr; curr = curr->next) {
        out += std::to_string(curr->data);
        if (curr->next != nullptr) {
            out += " -> ";
        }
    }
    return out;
}

// --------------------------------------------------------------
// TODO -- Task A: void LinkedList::prepend(int value)
// Insert value at the FRONT of the list, in O(1).
void LinkedList::prepend(int value) {
    Node* newNode = new Node{value, head_};
    head_ = newNode;
}

// TODO -- Task B: void LinkedList::append(int value)
// Insert value at the BACK of the list. Remember the empty list.
void LinkedList::append(int value) {
    Node* newNode = new Node{value, nullptr};
    if (head_ == nullptr) {
        head_ = newNode;
    } else {
        Node* curr = head_;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// TODO -- Task C: bool LinkedList::insertAt(int pos, int value)
// Insert value so that it ends up at index pos (0-based). Inserting at
// pos == size() appends. Return false and change nothing if pos is
// negative or greater than size().
bool LinkedList::insertAt(int pos, int value) {
    if (pos < 0 || pos > size()) {
        return false;
    }
    if (pos == 0) {
        prepend(value);
        return true;
    }
    Node* newNode = new Node{value, nullptr};
    Node* curr = head_;
    for (int i = 0; i < pos - 1; ++i) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
    return true;
}

// TODO -- Task D: bool LinkedList::removeValue(int target)
// Remove the FIRST node whose data equals target and free it. Return
// false if the value is not in the list.
bool LinkedList::removeValue(int target) {
    if (head_ == nullptr) {
        return false;
    }
    if (head_->data == target) {
        Node* toDelete = head_;
        head_ = head_->next;
        delete toDelete;
        return true;
    }
    Node* curr = head_;
    while (curr->next != nullptr && curr->next->data != target) {
        curr = curr->next;
    }
    if (curr->next != nullptr) {
        Node* toDelete = curr->next;
        curr->next = curr->next->next;
        delete toDelete;
        return true;
    }
    return false;
}

// TODO -- Task E: void LinkedList::reverse()
// Reverse the list IN PLACE -- no new nodes, no deleted nodes.
void LinkedList::reverse() {
    Node* prev = nullptr;
    Node* curr = head_;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head_ = prev; // Update head to the new front of the list
}

// TODO -- Task F (optional, not graded): bool LinkedList::removeAt(int pos)
// Remove the node at index pos. Return false if pos is out of range.
// --------------------------------------------------------------