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

using namespace std;

void BFS (int source, vector<vector<int>> adj) {
    queue<int> q;
    vector<bool> visit(adj.size(), false);
    vector<int> level(adj.size(), 0);
 
    q.push(source);
    level[source] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        for (w : adj[v]) {
            if (!visit[v]) {
                level[adj[v][w]] = level[v] + 1;
                q.push(w);
                visit[w] = true;
            }
        }
    }

    for (auto& v : level)
        cout << "Node " << v - level.begin() << " at level " << *v << endl;
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