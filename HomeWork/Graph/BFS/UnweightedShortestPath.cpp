#include <iostream>
#include <vector>

using namespace std;

void construct_graph (vector<vector<int>>& adj, int nodes, int edges) {
    adj.resize(nodes);
    while (edges > 0) {
        int A, B;
        cout << "Enter the adge A--B:";
        cin >> A >> B;
        adj[A].push_back(B);
        edges--;
    }
}

vector<int> BFS (vector<vector<int>> adj, int source) {
    cout << "enter BFS " << endl;
    vector<int> parent(adj.size(), -1);
    vector<vector<int>> level;
    level.push_back({source});

    while (level.back().size() > 0) {
        level.push_back({});
        for (auto e : level.rbegin()[1]) {
            for (auto v : adj[e]) {
                if (parent[v] == -1) {
                    parent[v] = e;
                    level.back().push_back(v);
                }
            }
        }
    }

    return parent;
}

vector<int> shortest_path (vector<vector<int>> adj, int s, int t) {
    vector<int> path;
    vector<int> parent = BFS(adj, s);
    if (parent[t] < 0)
        return {};
    int i = t;
    path.push_back(t);
    while (i != s) {
        i = parent[i];
        path.push_back(i);
    }
    return path;
}

int main () {
    vector<vector<int>> adj;
    vector<int> path;
    int s = 0, t =2;
    construct_graph(adj, 5, 5);
    path = shortest_path(adj, s, t);
    cout << "\nshortest path from " << s << "-->" << t << endl;
    for (auto e : path)
        cout << e << "\t";
    cout << "\n";
    return 0;
}