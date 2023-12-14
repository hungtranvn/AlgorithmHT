#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj {
    {2},
    {7},
    {0,3,4},
    {2,4},
    {2,3,5,6},
    {4,6},
    {4,5},
    {1}
};
vector<int> visited(8, false);
vector<int> comp;

void DFS(int v) {
    visited[v] = true;
    comp.push_back(v);
    for (auto u : adj[v]) {
        if (!visited[u])    DFS(u);
    }
}

int main () {
    for (auto v = 0; v < adj.size(); ++v) {
        if (!visited[v]) {
            comp.clear();
            DFS(v);
            cout << "Component: ";
            for (auto u : comp)
                cout << u;
            cout << endl;
        }
    }
    return 0;
}