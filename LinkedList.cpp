#include "LinkedList.h"

// Constructor: Initializes an empty list
template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

// Destructor: Frees memory allocated for the list
template <typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Append: Add a node to the end of the list
template <typename T>
void LinkedList<T>::append(T value) {
    Node* newNode = new Node{ value, nullptr, nullptr };

    if (tail == nullptr) {
        head = tail = newNode; // If list is empty, both head and tail point to the new node
    }
    else {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode; // Update tail to the new node
    }
}

// RemoveTail: Delete the last node (tail node) specifically
template <typename T>
void LinkedList<T>::remove() {
    if (tail == nullptr) return; // If the list is empty, nothing to remove

    Node* temp = tail;

    // If there's only one node
    if (head == tail) {
        head = tail = nullptr;
    }
    // If there are multiple nodes
    else {
        tail = tail->previous; // Move tail pointer to the previous node
        tail->next = nullptr;  // Remove the connection to the old tail
    }

    delete temp; // Free memory of the old tail
}

// Print: Output the list contents
template <typename T>
void LinkedList<T>::print() const {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " <-> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}

// Size: Return the number of elements in the list
template <typename T>
int LinkedList<T>::size() const {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Explicitly tell the compiler to compile the template class for required types
template class LinkedList<std::shared_ptr<Circle>>;

