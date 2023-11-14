#include <iostream>
#include "SequenceInterfaceArray.hpp"
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
    return 0;
}
