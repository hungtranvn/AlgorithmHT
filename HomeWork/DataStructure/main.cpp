#include <iostream>
#include "SequenceInterfaceArray.hpp"
#include "SequenceInterfaceLinkedList.hpp"

using namespace std;

int main() {
    int arr[] = {0, 1, 2, 3, 4};
    SequenceInterfaceArray arr_seq(arr, sizeof(arr)/sizeof(int));
    cout << arr_seq.len() << endl;
    arr_seq.iter_seq();
    arr_seq.insert_at(0, 20);
    cout << endl;
    arr_seq.iter_seq();
    cout << endl;
    int x = arr_seq.delete_at(2);
    cout << endl;
    arr_seq.iter_seq();
    cout << endl;

    cout << "Test the LinkedList structure\n";

    SequenceInterfaceLinkedList list_seq(arr, sizeof(arr)/sizeof(int));
    cout << "The 2nd value: " << list_seq.get_at(1) << endl;
    list_seq.set_at(1, 10);
    cout << "The 2nd value: " << list_seq.get_at(1) << endl;

    return 0;
}
