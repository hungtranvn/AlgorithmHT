#include<SequenceInterfaceDynamicArray.hpp>

SequenceInterfaceDynamicArray::SequenceInterfaceDynamicArray(int r) : m_r(r) {
    this->_compute_bounds();
    this->_resize(0);
}

int SequenceInterfaceDynamicArray::len() const {
    return this->m_size;
}

void SequenceInterfaceDynamicArray::_compute_bounds() const {
    this->m_upper = 
}