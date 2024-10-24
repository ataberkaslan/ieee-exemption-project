#pragma once

#include "Library.h"

template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* previous;
    };

    Node* head;
    Node* tail;

public:
    LinkedList();
    ~LinkedList();

    void append(T value);
    void remove();
    void print() const;
    int size() const;

    // Iterator class
    class Iterator {
    private:
        Node* current; // Pointer to the current node in the list

    public:
        // Constructor for the iterator
        Iterator(Node* node) : current(node) {}

        // Dereference operator to access node data
        T& operator*() { return current->data; }

        // Pre-increment operator (++iter)
        Iterator& operator++() {
            if (current) current = current->next;
            return *this;
        }

        // Post-increment operator (iter++)
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        // Comparison operators
        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }
    };

    // Begin iterator (returns the start of the list)
    Iterator begin() { return Iterator(head); }

    // End iterator (returns one past the end of the list)
    Iterator end() { return Iterator(nullptr); }
};

