#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*brute force solution: O(n3)*/
int solution1(int target, vector<int>& nums) {
    int ans = INT_MAX;
    for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j = i; j < nums.size(); ++j) {
            int sum = 0;
            for (int k = i; k <= j; ++k) {
                sum += nums[k];
            }
            if (sum >= target)
                ans = min(ans, j - i + 1);   
        }
    }

    return (ans != INT_MAX) ? ans : 0;
}

int solution2(int target, vector<int>& nums) {
    int ans = INT_MAX;
    vector<int> sums(nums.size());
    sums[0] = sums[0];
    for (int i = 1; i < nums.size(); ++i) {
        sums[i] += sums[i - 1] + nums[i];
    }

    for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j = i; j < nums.size(); ++j) {
            int sum = sums[j] - sums[i] + nums[i];
            if (sum >= target)
                ans = min(ans, j - i + 1);
        }
    }

    return (ans != INT_MAX) ? ans : 0;
}

/*Binary search*/
int solution3(int target, vector<int>& nums) {
    int ans = INT_MAX;
    vector<int> sums(nums.size());
    sums[0] = sums[0];
    for (int i = 1; i < nums.size(); ++i) {
        sums[i] += sums[i - 1] + nums[i];
    }

    for (int i = 0; i < nums.size() - 1; ++i) {
        for (int j = i; j < nums.size(); ++j) {
            int sum = sums[j] - sums[i] + nums[j];
            if (sum >= target)
                ans = min(ans, j - i + 1);   
        }
    }

    return (ans != INT_MAX) ? ans : 0;
}

/*Sliding window*/
int solution4(int target, vector<int>& nums) {
    int ans = INT_MAX;
    int sum = 0;
    int start = 0;

    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        while (sum > target) {
            ans = min(ans, i - start + 1);
            sum -= nums[start++];
        }
    }
    return (ans != INT_MAX) ? ans : 0;
}

int main() {
    int target = 7;
    vector<int> nums{2,3,1,2,4,3};
    cout << solution4(target, nums) << endl;
    return 0;
}