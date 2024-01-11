#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> nums{-1,0,1,2,-1,-4};
    vector<vector<int>> ret;
    set<vector<int>> set;

    sort(nums.begin(), nums.end(), [](int a, int b) {return a < b;});
    for (auto i = 0; i < nums.size(); ++i) {
        int low = i + 1;
        int high = nums.size() - 1;

        while (low < high) {
            int sum = nums[low] + nums[i] + nums[high];
            if (sum == 0) {
                set.insert({nums[low], nums[i], nums[high]});
                low++;
                high--;
            } else if (sum < 0) {
                low++;
            } else {
                high--;
            }
        }
    }

    for (auto e : set) {
        ret.push_back(e);
    }
    return 0;
}