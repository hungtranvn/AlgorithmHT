#include<SequenceInterfaceDynamicArray.hpp>
#include<bits/stdc++.h>

SequenceInterfaceDynamicArray::SequenceInterfaceDynamicArray(int r) : m_r(r) {
    compute_bounds();
    resize(0);
}

int SequenceInterfaceDynamicArray::len() const {
    return m_size;
}

void SequenceInterfaceDynamicArray::compute_bounds() {
    m_upper = len();
    m_lower = (int)len() / (m_r * m_r);
}

void SequenceInterfaceDynamicArray::resize(int n) {
    if (m_lower < n < m_upper)  return;
    int m = std::max(n, 1) * m_r;
    
    int* temp = new int(m);
    SequenceInterfaceStaticArray::copy_forward(0, m_size, temp, 0);
    if (m_parr != nullptr) {
        delete [] m_parr;
    }
    m_parr = temp;
    compute_bounds();
}

void SequenceInterfaceDynamicArray::insert_last(int x) {
    resize(this->m_size + 1);
    m_parr[m_size] = x;
    m_size += 1;
}

void SequenceInterfaceDynamicArray::delete_last() {
    m_size -= 1;
    resize(m_size);
}

void SequenceInterfaceDynamicArray::insert_at(int i, int x) {

}

int SequenceInterfaceDynamicArray::delete_at(int i) {

}

void SequenceInterfaceDynamicArray::insert_first(int x) {

}

int SequenceInterfaceDynamicArray::delete_first() {
    
}
