#include <iostream>
#include <vector>

using namespace std;

vector<int> nums = {1,2,3};
vector<vector<int>> ans;

void print_2dvector(vector<vector<int>>& v) {
    for (auto &it : v) {
        for (auto &e : it)
            cout << e;
        cout << endl;
    }
}

bool is_contain(int key, vector<int> v) {
    bool ret = false;
    for (auto &e : v) {
        if (key == e) {
            ret = true;
            break;
        }
    }
    return ret;
}

void solve_backtrack(vector<int>& nums, vector<int> track) {
    if (track.size() == nums.size()) {
        ans.push_back(track);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (is_contain(nums[i], track))
            continue;
        track.push_back(nums[i]);
        solve_backtrack(nums, track);
        track.pop_back();
    }
}

int main() {
    vector<int> track = {};
    solve_backtrack(nums, track);
    print_2dvector(ans);
    return 0;
}