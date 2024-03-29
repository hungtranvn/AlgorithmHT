#include <iostream>
#include "HashTable.hpp"

DirectAccessArray::DirectAccessArray(int u) {
    m_parr = new int[u];
}

DirectAccessArray::DirectAccessArray(int u) {
    delete [] m_parr;
}

int main() {

    return 0;
}