#include "SequenceInterfaceArray.hpp"
#include <iostream>

using namespace std;

void SequenceInterfaceArray::insert_at(int index, int value) {
    int* temp = new int(_size + 1);
    this->_copy_forward(0, index, temp, 0);
    temp[index] = value;
    this->_copy_backward(index, _size - index, temp, index + 1);
    this->_build(temp, _size + 1);
    delete [] temp;
}

int SequenceInterfaceArray::delete_at(int index) {
    int* temp = new int(_size - 1);
    this->_copy_forward(0, index, temp, 0);
    int x = _arr[index];
    this->_copy_backward(index + 1, _size - index - 1, temp, index);
    this->_build(temp, _size - 1);
    delete [] temp;
    return x;
}

void SequenceInterfaceArray::insert_first(int value) {
    this->insert_at(0, value);
}

int SequenceInterfaceArray::delete_first() {
    return this->delete_at(0);
}

void SequenceInterfaceArray::insert_last(int value) {
    this->insert_at(_size - 1, value);
}

int SequenceInterfaceArray::delete_last(int value) {
    return this->delete_at(_size - 1);
}

void SequenceInterfaceArray::_copy_backward(int i, int n, int A[], int j) {
    // A[0, 1, _, _] ==> B[_, _, 0, 1]
    for (int k = n - 1; k >= 0 ; --k) {
        A[j + k] = _arr[i + k];
    }
}

void SequenceInterfaceArray::_copy_forward(int i, int n, int A[], int j) {
    // A[_, _, 2, 3] ==> B[2, 3, _, _]
    for (int k = 0; k < n ; ++k) {
        A[j + k] = _arr[i + k];
    }
}

int SequenceInterfaceArray::get_at(int index) const {
    if (index < 0 || index >= _size)
        return -1;
    return _arr[index];
}

void SequenceInterfaceArray::set_at(int index, int value) {
    if (index < 0 || index >= _size) {
        //do nothing
    }
    else {
        _arr[index] = value;
    }
}

void SequenceInterfaceArray::_build(int seq[], int size) {
    if (_arr != nullptr) {
        delete [] _arr;
    }

    _size = size;
    _arr = new int(_size);
    for (auto i = 0; i < _size; ++i) {
        _arr[i] = seq[i];
    }
}

int SequenceInterfaceArray::len() const {
    return _size;
}

void SequenceInterfaceArray::iter_seq() const {
    for (auto i = 0; i < _size; ++i) {
        cout << _arr[i] << "\t";
    }
}

SequenceInterfaceArray::SequenceInterfaceArray(int seq[], int size) {
    this->_build(seq, size);
}

SequenceInterfaceArray::~SequenceInterfaceArray() {
    delete[] _arr;
}