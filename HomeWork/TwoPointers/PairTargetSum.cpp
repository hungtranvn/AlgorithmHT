#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int target = 17;
    vector<int> arr{2, 5, 3, 8, 6, 1, 4, 9};
    sort(arr.begin(), arr.end(), [](int a, int b){return a < b;});
    for (auto e: arr)
        cout << e << "\t";
    cout << "\n";
    
    auto start = arr.begin();
    auto end = arr.end() - 1;

    while (start < end) {
        int sum = *start + *end;
        if (sum == target) {
            break;
        } else if (sum < target) {
            start++;
        } else {
            end--;
        }
    }
    
    return 0;
}