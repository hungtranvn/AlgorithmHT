#include <iostream>
#include <vector>
#include <stack>

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
vector<bool> visited(8, false);
vector<int> comp;

void DFS(int v) {
    visited[v] = true;
    comp.push_back(v);
    for (auto u : adj[v]) {
        if (!visited[u])    DFS(u);
    }
}

void iterative_DFS (int source) {
    stack<int> s;

    s.push(source);
    visited[source] = true;

    while(!s.empty()) {
        int v = s.top();
        s.pop();
        comp.push_back(v);
        for (auto w : adj[v]) {
            if (!visited[w]) {
                s.push(w);
                visited[w] = true;
            }
        }
    }
}

int main () {
    for (auto v = 0; v < adj.size(); ++v) {
        if (!visited[v]) {
            comp.clear();
            iterative_DFS(v);
            cout << "Component: ";
            for (auto u : comp)
                cout << u;
            cout << endl;
        }
    }
    return 0;
}