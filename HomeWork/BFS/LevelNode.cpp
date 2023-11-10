/*
You have been given a Tree consisting of N nodes. A tree is a fully-connected graph consisting of N nodes and edges. 
The nodes in this tree are indexed from 1 to N. Consider node indexed 1 to be the root node of this tree.
The root node lies at level one in the tree.
You shall be given the tree and a single integer x.
You need to find out the number of nodes lying on level x.

Input Format
The first line consists of a single integer N denoting the number of nodes in the tree.
Each of the next lines consists of 2 integers a and b denoting an undirected edge between node a and node b.
The next line consists of a single integer x.

Output Format
You need to print a single integers denoting the number of nodes on level x.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

/*
void BFS (int source, vector<vector<int>> adj) {
    queue<int> q;
    vector<bool> visit(adj.size(), false);
    vector<int> level(adj.size(), 0);
 
    q.push(source);
    level[source] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (auto w : adj[v]) {
            if (!visit[adj[v][w]]) {
                level[adj[v][w]] = level[v] + 1;
                q.push(adj[v][w]);
                visit[adj[v][w]] = true;
            }
        }
    }

    for_each(level.begin(), level.end(), [](const int n) {cout << n; });
}
*/

vector<int> BFS (vector<vector<int>> adj, int source) {
    vector<int> parent(adj.size(), -1);
    parent[source] = source;
    vector<vector<int>> level;
    level.push_back({source});

    while (0 < level.back().size()) {
        level.push_back({});
        // loop all the last level
        for (int i = 0; i < level[level.size() - 2].size(); ++i){
            // Check all 
            for (int v = 0; v < adj[i].size(), ++v) {
                if (parent[v] == -1) {
                    parent[v] = level[level.size() - 2][i];
                    level.back().push_back(v);
                }
            }
        }
    }

    return parent;
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and number of adges: ";
    cin >> nodes >> edges;

    vector<vector<int>> adj(nodes);

    while (edges > 0) {
        int A, B;
        cout << "Enter the adge A--B:";
        cin >> A >> B;
        adj[A].push_back(B);
        edges--;
    }

    int source;
    cout << "Enter source: ";
    cin >> source;
    BFS(source, adj);

    return 0;
}