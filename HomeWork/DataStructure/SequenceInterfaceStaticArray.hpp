#ifndef _SEQUENCE_INTERFACE_STATIC_ARRAY_H
#define _SEQUENCE_INTERFACE_STATIC_ARRAY_H

using namespace std;

class SequenceInterfaceStaticArray {
private:
    int *_arr = nullptr;
    int _size = 0;
protected:
    void copy_forward(int i, int n, int A[], int j);
    void copy_backward(int i, int n, int A[], int j);
public:

    // dynamic
    void insert_at(int index, int value);
    int delete_at(int index);
    void insert_first(int value);
    int delete_first();
    void insert_last(int value);
    int delete_last(int value);

    // static
    int get_at(int index) const;
    void set_at(int index, int value);
    void iter_seq() const;
    
    // container
    void build(int seq[], int size);
    int len() const;
    
    // constructor/destructor
    SequenceInterfaceStaticArray(int seq[], int size);
    virtual ~SequenceInterfaceStaticArray();
};
#endif //_SEQUENCE_INTERFACE_STATIC_ARRAY_H

