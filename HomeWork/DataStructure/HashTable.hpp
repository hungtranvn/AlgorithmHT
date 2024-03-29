#ifndef _HASH_TABLE_
#define _HASH_TABLE_

using namespace std;

class DirectAccessArray {
    int m_u;
    int* m_parr;
public:
    int search(int key);
    void delete(int key);
    void insert(int x);
    int findNext(int key);
    int findPrev(int key);
    int findMax(int key);
    void deleteMax();
    DirectAccessArray(int u);
    ~DirectAccessArray();
};

#endif