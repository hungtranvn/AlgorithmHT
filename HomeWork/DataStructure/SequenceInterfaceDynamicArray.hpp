#ifndef _SEQUENCE_INTERFACE_DYNAMIC_ARRAY_H
#define _SEQUENCE_INTERFACE_DYNAMIC_ARRAY_H
#include <SequenceInterfaceArray.hpp>
class SequenceInterfaceDynamicArray : public SequenceInterfaceArray {
private:
    int m_size = 0;
    int m_r = 0;
    int m_upper = 0;
    int m_lower = 0;
    void _compute_bounds() const;
    void _resize(int n);
public:
    //container
    int len() const;
    void build(int seq[], int size);

    void insert_last(int value);
    void delete_last();
    void insert_at(int i, int value);
    int delete_at(int i, int value);
    void insert_first(int value);
    int delete_first();

    SequenceInterfaceDynamicArray(int r);
};
#endif //_SEQUENCE_INTERFACE_DYNAMIC_ARRAY_H