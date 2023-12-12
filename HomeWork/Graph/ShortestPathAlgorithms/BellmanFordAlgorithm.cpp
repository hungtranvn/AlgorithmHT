#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <string>

#include <limits.h>
#include <algorithm>

using namespace std;

vector<vector<int>> adj {
    {1,2,3},
    {0,2},
    {0,1,3},
    {0,2},
};

vector<vector<int>> weights {
    {0, 1, 3, 4},
    {1, 0, 2, 0},
    {3, 2, 0, 5},
    {4, 0, 5, 0},
};

vector<int> d(adj.size(), INT_MAX);
vector<int> p(adj.size(), -1);

void try_to_relax(vector<vector<int>>& adj, vector<vector<int>>& weights, int u, int v) {
    if (d[v] > d[u] + weights[u][v]) {
        d[v] = d[u] + weights[u][v];
        p[v] = u;
    }
}

void bellman_ford(vector<vector<int>>& adj, vector<vector<int>>& weights, int source) {
    d[source] = 0;
    p[source] = source;
    
    for (int i = 0; i < adj.size() - 1; ++i) {
        for (auto u = 0; v < adj.size(); ++j) {
            for (auto v : adj[u] {
                try_to_relax(adj, weights, u, v);
            }
        }
    }
}

int main() {
    return 0;
}