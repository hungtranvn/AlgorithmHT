#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void visit_land(vector<vector<int>>& matrix, int i, int j) {
    if(i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size())   return;

    if(matrix[i][j] == 0)   return;

    matrix[i][j] = 0;
    visit_land(matrix, i+1, j);
    visit_land(matrix, i-1, j);
    visit_land(matrix, i, j-1);
    visit_land(matrix, i, j+1);
}

int count_island(vector<vector<int>>& matrix) {
    int ans = 0;
    
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                ans++;
                visit_land(matrix, i, j);
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> matrix {
        {0, 1, 1, 1, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {1, 1, 0, 0, 1},
        {1, 0, 0, 0, 1}
    };
    cout << "The number of island: " << count_island(matrix) << endl;
    return 0;
}