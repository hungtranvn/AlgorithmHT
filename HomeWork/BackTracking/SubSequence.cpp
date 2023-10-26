  /*
  * https://labuladong.gitbook.io/algo-en/iii.-algorithmic-thinking/subset_permutation_combination
  * https://manvityagi770.medium.com/backtracking-subsets-problem-part-2-df5dfd33e89d
  * https://www.topcoder.com/thrive/articles/print-all-subset-for-set-backtracking-and-bitmasking-approach
  * 
  */
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> nums = {1, 2, 3};
vector<vector<int>> subsets;

void print_1dvector(vector<int> v) {
    for (auto &e : v)
        cout << e;
    cout << endl;
}

void print_2dvector(vector<vector<int>> v) {
    for (auto &it : v) {
        for (auto &e : it)
            cout << e;
        cout << endl;
    }
}

void solve_bitmask(vector<int>& nums) {
    int n = pow(2, nums.size());
    for (size_t i = 0; i< n; ++i) {
        int temp = i;
        string set = "";
        for (size_t j = nums.size() - 1; j >= 0;--j) {
            int re = temp % 2;
            temp = temp / 2;
            if (re == 0) {

            } else {
                set = to_string(nums[j]) + set;
            }
        }
        cout << set << endl;
    }
}

vector<vector<int>> solve_reduction (vector<int>& nums) {
    if (nums.empty()) {
        return {{}};
    }

    int n = nums.back();
    nums.pop_back();

    vector<vector<int>> rets = solve_reduction(nums);

    for (auto i = 0; i < rets.size(); ++i) {
        rets.push_back(rets[i]);
        rets.back().push_back(n);
    }

    return rets;
}

void solve_backtrack_1(vector<int>& nums, int start, vector<int>& track) {
    subsets.push_back(track);
    if (start == nums.size())
        return;
    
    for (auto i = start; i < nums.size(); ++i) {
        track.push_back(nums[i]);
        solve_backtrack_1(nums, i + 1, track);
        track.pop_back();
    }
}

void solve_backtrack_2(vector<int>& nums, int start, vector<int> track) {
    // base case
    if (start == nums.size()) {
        subsets.push_back(track);
        return;
    }

    // for every element in nums, we have two choices
    track.push_back(nums[start]);
    solve_backtrack_2(nums, start + 1, track);

    track.pop_back();
    solve_backtrack_2(nums, start + 1, track);
}

int main() {
    cout << "back tracking solution: include and exclude method" << endl;
    vector<int> track;
    solve_backtrack_2(nums, 0, track);
    print_2dvector(subsets);
    return 0;
}