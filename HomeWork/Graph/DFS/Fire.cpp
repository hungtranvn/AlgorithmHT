/* Problem: https://www.codechef.com/problems/FIRESC
** Analysis:
*/
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

int DFS(vector<vector<int>>& adj_list, int source, vector<bool> is_visited) {
    int friend_members = 1;
    stack<int> st;
    st.push(source);
    while(!st.empty()) {
        int to_visit = st.top();
        st.pop();
        for (auto e : adj_list[to_visit]) {
            if(!is_visited[e]) {
                friend_members++;
                st.push(e);
                is_visited[e] = true;
            }
        }
    }
    return friend_members;
}

vector<int> solve(vector<vector<int>>& adj_list) {
    vector<int> friend_groups;
    vector<bool> is_visited(adj_list.size(), false);
    for (auto i = 0; i < adj_list.size(); ++i) {
        if (!is_visited[i]) {
            friend_groups.push_back(DFS(adj_list, i, is_visited));
        }
    }
    long long captain_ways = 1;
    for (auto e : friend_groups) {
        captain_ways = (captain_ways*e)%MOD;
    }
    return {friend_groups.size(), captain_ways};
}

int main() {
    int T;
    while (T) {
        int N, M;
        cin>>N>>M;
        vector<vector<int>> adj_list(N);
        while(M) {
            int node1, node2;
            cin>>node1>>node2;
            node1--;
            node2--;
            adj_list[node1].push_back(node2);
            adj_list[node2].push_back(node1);
            M--;
        }
        vector<int> ret = solve(adj_list);
        cout << ret[1] << " " << ret[2] << endl;
        T--;
    }
    return 0;
}