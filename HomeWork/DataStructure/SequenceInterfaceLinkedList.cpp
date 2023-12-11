#include "SequenceInterfaceLinkedList.hpp"
#include <iostream>

int SequenceInterfaceLinkedList::len() const {
    return this->_size;
}

void SequenceInterfaceLinkedList::iter() const {
    Node* node = this->head;
    while (node) {
        std::cout << node->item << "\t";
        node = node->next;
    }
}

void SequenceInterfaceLinkedList::_build(int seq[], int size) {
    _size = size;
    for (auto i = _size - 1; i >= 0; --i) {
        this->insert_first(seq[i]);
    }
}

int SequenceInterfaceLinkedList::get_at(int i) const {
    Node* node = this->head->later_node(i);
    return node->item;
}

void SequenceInterfaceLinkedList::set_at(int i, int value) {
    Node* node = this->head->later_node(i);
    node->item = value;
}

void SequenceInterfaceLinkedList::insert_first(int value) {
    Node* new_node = new Node(value);
    new_node->next = this->head;
    this->head = new_node;
    this->_size += 1;
}

int SequenceInterfaceLinkedList::delete_first() {
    int x = this->head->item;
    this->head = this->head->next;
    this->_size -= 1;
    return x;
}

void SequenceInterfaceLinkedList::insert_at(int i, int value) {
    if (i == 0) {
        this->insert_first(value);
        return;
    }
    
    Node* new_node = new Node(value);
    Node* node = this->head->later_node(i);
    new_node->next = node->next;
    node->next = new_node;
    this->_size++;
}

int SequenceInterfaceLinkedList::delete_at(int i) {
    if (i == 0) {
        return this->delete_first();
    }

    Node* node = this->head->later_node(i);
    int x = node->next->item;
    node->next = node->next->next;
    this->_size--;
    return x;
}

void SequenceInterfaceLinkedList::insert_last(int value) {
    this->insert_at(this->_size, value);
} 

int SequenceInterfaceLinkedList::delete_last() {
    return this->delete_at(this->_size - 1);
}

SequenceInterfaceLinkedList::SequenceInterfaceLinkedList(int seq[], int size){
    this->_build(seq, size);
}