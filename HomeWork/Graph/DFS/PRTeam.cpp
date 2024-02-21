/* problem: https://www.spoj.com/problems/CAM5/
** Problem statement: You are given an undrirected graph, find the number of connected component.
*/
#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<int>>& adj_list, int source, vector<bool>& is_visited) {
    stack<int> s;
    s.push(source);
    is_visited[source] = true;
    while (!s.empty()) {
        int visit = s.top();
        s.pop();
        for (auto e : adj_list[visit]) {
            if (!is_visited[e]) {
                s.push(e);
                is_visited[e] = true;
            }
        }
    }
}

int solve(vector<vector<int>> adj_list) {
    int ret = 0;
    vector<bool> is_visited(adj_list.size(), false);
    
    for (int i=0; i < adj_list.size(); ++i) {
        if (is_visited[i] == false) {
            ret++;
            DFS(adj_list, i, is_visited);
        }
    }
    return ret !=0 ? ret : adj_list.size();
}

int main() {
    int t; // test cases
    cin>>t;
    while (t) {
        int nodes; // number of nodes
        int edges;
        cin>>nodes>>edges;
        vector<vector<int>> adj_list(nodes);
        while (edges) {
            int node1, node2;
            cin>>node1>>node2;
            adj_list[node1].push_back(node2);
            adj_list[node2].push_back(node1);
            edges--;
        }
        cout << solve(adj_list) << endl;
        t--;
    }
    return 0;
}