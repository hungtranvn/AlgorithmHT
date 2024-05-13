#include <bits/stdc++.h>

using namespace std;

int solve_tastiness(vector<int>& price) {
    int max = 0;
    int n = price.size();
    for (auto i = 0; i < n - 2; i++) {
        for (auto j = i + 1; j < n - 1; j++) {
            for (auto k = j + 1; k < n; k++) {
                int t1 = abs(price[i] - price[j]);
                int t2 = abs(price[i] - price[k]);
                int t3 = abs(price[j] - price[k]);
                
                int m = min({t1, t2, t3});
                max = m > max ? m : max;
            }
        }
    }
    return max;
}

int main() {
    int k = 3;
    vector<int> price{13, 5, 1, 8, 21, 2};
    cout << solve_tastiness(price);
    return 0;
}
