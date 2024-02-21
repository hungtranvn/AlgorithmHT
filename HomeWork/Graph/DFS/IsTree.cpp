#include<bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>>& adj_list, int source, vector<bool>& is_visited) {
    stack<int> st;
    st.push(source);
    while (!st.empty()) {
        int visit = st.top();
        st.pop();
        for (auto e : adj_list[visit]) {
            if (!is_visited[e]) {
                st.push(e);
                is_visited[e] = true;
            }
        }
    }
}

bool solve(vector<vector<int>>& adj_list) {
    bool ret = true;
    int count = 0;
    vector<bool> is_visited(adj_list.size(), false);
    for (auto i = 1; i < adj_list.size(); ++i) {
        if(!is_visited[i]) {
            count++;
            dfs(adj_list, i, is_visited);
        }
    }
    return count < 2 ? ret : false;
}

int main() {
    int nodes;
    int edges;
    cin>>nodes>>edges;
    vector<vector<int>> adj_list(nodes);
    while (edges) {
        int node1, node2;
        cin>>node1>>node2;
        adj_list[node1-1].push_back(node2-1);
        adj_list[node2-1].push_back(node1-1 );
        edges--;
    }
    if(solve(adj_list))
        cout << "It is a tree" << endl;
    else
        cout << "It is not a tree" << endl;
    return 0;
}