#ifndef _SEQUENCE_INTERFACE_DYNAMIC_ARRAY_H
#define _SEQUENCE_INTERFACE_DYNAMIC_ARRAY_H
#include <SequenceInterfaceStaticArray.hpp>

class SequenceInterfaceDynamicArray : public SequenceInterfaceStaticArray {
private:
    int *m_parr = nullptr;
    int m_size = 0;
    int m_r = 2;
    int m_upper = 0;
    int m_lower = 0;
    void compute_bounds();
    void resize(int n);
public:
    //container
    int len() const;
    void build(int seq[], int size);

    void insert_last(int value);
    void delete_last();
    void insert_at(int i, int value);
    int delete_at(int i);
    void insert_first(int value);
    int delete_first();

    SequenceInterfaceDynamicArray(int r);
};
#endif //_SEQUENCE_INTERFACE_DYNAMIC_ARRAY_H