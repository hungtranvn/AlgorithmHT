#include <iostream>
#include <vector>

using namespace std;

vector<int> nums = {1,2,3,4};
vector<vector<int>> ans;

void print_2dvector(vector<vector<int>>& v) {
    for (auto &it : v) {
        for (auto &e : it)
            cout << e;
        cout << endl;
    }
}

void solve_backtrack(vector<int>& nums, int k, int start, vector<int> track) {
    if (k == track.size()) {
        ans.push_back(track);
        return;
    }

    for (int i = start; i < nums.size(); ++i) {
        track.push_back(nums[i]);
        solve_backtrack(nums, k, i + 1, track);
        track.pop_back();
    }
}

int main() {
    int k = {2};
    vector<int> track = {};
    solve_backtrack(nums, k, 0, track);
    print_2dvector(ans);
    return 0;
}