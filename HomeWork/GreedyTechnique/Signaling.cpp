#include <iostream>
#include <vector>

using namespace std;

int max_consecutive_high_signal(string& signals) {
    int ret = 0;
    int count = 0;
    for (auto e : signals) {
        int ie = (int)e - '0';
        if (ie == 1) count++;
        else    count = 0;
        ret = ret < count ? count : ret;
    }
    return ret;
}

int main() {
    int test_num = 0;
    cin >> test_num;
    while (test_num > 0) {
        int str_size = 0;
        cin >> str_size;
        string str;
        cin >> str;
        cout << max_consecutive_high_signal(str) << endl;
        test_num--;
    }
    return 0;
}