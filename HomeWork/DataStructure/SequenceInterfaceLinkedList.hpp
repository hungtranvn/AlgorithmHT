#ifndef SEQUEMCE_INTERFACE_LINKED_LIST_H
#define SEQUENCE_INTERFACE_LINKED_LIST_H

struct Node {
    int item {0};
    Node* next {nullptr};

    Node(int x) : item(x) {
        this->next = nullptr;
    }
    Node* later_node(int i) {
        if (i == 0) {
            return this;
        }
        return this->next->later_node(i-1);
    }
};

class SequenceInterfaceLinkedList {
    Node* head {nullptr};
    int size {0};

    int len() const;
    void iter() const;
    void build();

public: 
    int get_at(int i) const;
    void set_at(int i, int value);
    void insert_first(int value);
    int delete_first();
    void insert_at(int i, int value);
    int delete_at(int i);
    void insert_last(int value);
    int delete_last();
};
#endif //SEQUENCE_INTERFACE_LINKED_LIST_H
