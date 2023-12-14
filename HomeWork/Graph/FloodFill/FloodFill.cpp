#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

vector<vector<int>> board {
    {0,0,1,1,2},
    {0,0,0,2,2},
    {3,0,0,0,0},
    {3,0,0,0,0},
    {3,1,1,1,1}
};

vector<vector<bool>> is_visited(5, vector<bool>(5, false));

bool is_valid(int row, int columm, int target_color) {
    if (row < 0 || columm > 4)  return false;
    if (columm < 0 || columm > 4)   return false;
    if (board[row][columm] != target_color || is_visited[row][columm]) return false;
    
    cout << "target color: " << target_color << endl;
    return true;
}

void BFS_let_color(pair<int, int> start, int new_color) {
    int target_color = board[start.first][start.second];
    queue<pair<int, int>> q;
    q.push(start);
    is_visited[start.first][start.second] = true;
    board[start.first][start.second] = new_color;

    while(!q.empty()) {
        pair<int, int> current = q.front();
        board[current.first][current.second] = new_color;
        q.pop();

        if(is_valid(current.first + 1, current.second, target_color)) {
            q.push(make_pair(current.first + 1, current.second));
            is_visited[current.first + 1][current.second] = true;
            board[current.first + 1][current.second] = new_color;
        }

        if(is_valid(current.first - 1, current.second, target_color)) {
            q.push(make_pair(current.first - 1, current.second));
            is_visited[current.first - 1][current.second] = true;
            board[current.first - 1][current.second] = new_color;
        }
        
        if(is_valid(current.first, current.second + 1, target_color)) {
            q.push(make_pair(current.first, current.second + 1));
            is_visited[current.first][current.second + 1] = true;
            board[current.first][current.second + 1] = new_color;
        }

        if(is_valid(current.first, current.second - 1, target_color)) {
            q.push(make_pair(current.first, current.second - 1));
            is_visited[current.first][current.second - 1] = true;
            board[current.first][current.second - 1] = new_color;
        }
    }
};

void shorter_BFS_let_color(pair<int, int> start, int new_color) {
    vector<int> delta_x{1, -1, 0, 0};
    vector<int> delta_y{0, 0, 1, -1};
    
    int target_color = board[start.first][start.second];
    queue<pair<int, int>> q;
    q.push(start);
    is_visited[start.first][start.second] = true;
    board[start.first][start.second] = new_color;

    while(!q.empty()) {
        pair<int, int> current = q.front();
        board[current.first][current.second] = new_color;
        q.pop();

        cout << "visit position: " << current.first << " " << current.second << endl;
        for (int i = 0; i <= 3; ++i) {
            int next_row = current.first + delta_x[i];
            int next_columm = current.second + delta_y[i];
            cout << "next position: " << next_row << " " << next_columm << endl;
            
            if(is_valid(next_row, next_columm, target_color)) {
                cout << "push queue: " << next_row << " " << next_columm << endl;
                q.push(make_pair(next_row, next_columm));
                is_visited[next_row][next_columm] = true;
                board[next_row][next_columm] = new_color;
            }
        }
    }
};

int main() {
    for (auto u : board) {
        for (auto v : u) {
            cout << v;
        }
        cout << endl;
    }
    pair<int, int> start = make_pair(2,2);
    // BFS_let_color(start, 7);
    // cout << "after color" << endl;
    // for (auto u : board) {
    //     for (auto v : u) {
    //         cout << v;
    //     }
    //     cout << endl;
    // }
    cout << "shorter BFS" << endl;
    shorter_BFS_let_color(start, 8);
    for (auto u : board) {
        for (auto v : u) {
            cout << v;
        }
        cout << endl;
    }
    return 0;
}