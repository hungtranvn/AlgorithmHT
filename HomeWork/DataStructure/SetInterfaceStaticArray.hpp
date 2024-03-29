#ifndef _SET_INTERFACE_STATIC_ARRAY_HPP
#define _SET_INTERFACE_STATIC_ARRAY_HPP
#include<SequenceInterfaceStaticArray.hpp>

class SetInterfaceStaticArray : public SequenceInterfaceStaticArray {
private:
    SequenceInterfaceStaticArray s;
public:
    SetInterfaceStaticArray();
    ~SetInterfaceStaticArray();
};
#endif //_SET_INTERFACE_STATIC_ARRAY_HPP