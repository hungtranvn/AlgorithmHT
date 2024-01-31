#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int min_number_of_coins(vector<int>& coins, int n) {
    int ans = 0;
    for (int i = coins.size() - 1; i >= 0; i--) {
        if (coins[i] <= n) {
            int a = n / coins[i];
            ans += a;
            n -= a*coins[i];
        } else {
            break;
        }
    }
    return ans;
}

int main() {
    vector<int> coins = {1,2,5,10,20,50,100,200};
    int n = 700;
    cout << min_number_of_coins(coins, n) << endl;
    return 0;
}