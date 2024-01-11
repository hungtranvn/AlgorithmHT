#ifndef _BINARY_NODE_HPP
#define _BINARY_NODE_HPP

struct BinaryNode {
    int item;
    BinaryNode* left = nullptr;
    BinaryNode* right = nullptr;
    BinaryNode* parent = nullptr;

    BinaryNode(int value) : item(value) {

    }
};

#endif //_BINARY_NODE_HPP