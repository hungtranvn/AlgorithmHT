#include "SequenceInterfaceLinkedList.hpp"
#include <iostream>

int SequenceInterfaceLinkedList::len() const {
    return this->size;
}

void SequenceInterfaceLinkedList::iter() const {
    Node* node = this->head;
    while (node) {
        std::cout << node->item << "\t";
        node = node->next;
    }
}

void SequenceInterfaceLinkedList::insert_first(int value) {
    Node* newNode = new Node(value);
    newNode->next = this->head;
    this->head = newNode;
    this->size += 1;
}

