/*
You have been given an undirected graph consisting of N nodes and M edges. 
This graph can consist of self-loops as well as multiple edges. 
In addition , you have also been given Q queries. 
For each query , you shall be given 2 integers A and B. 
You just need to find if there exists an edge between node A and node B. 
If yes, print "YES" (without quotes) else , print "NO"(without quotes).

Input Format:
The first line consist of 2 integers N and M denoting the number of nodes and edges respectively. 
Each of the next M lines consist of 2 integers A and B denoting an undirected edge between node A and B. 
The next line contains a single integer Q denoting the number of queries. 
The next Line contains 2 integers A and B denoting the details of the query.
Output Format
Print Q lines, the answer to each query on a new line.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;

bool is_existed (const pair<int, int>& edge, vector<vector<int>>& adj) {
    int first = edge.first;
    int second = edge.second;
    bool ret = false;
    for (int i = 0; i < adj.size(); ++i) {
        if (find(adj[first].begin(), adj[first].end(), second) != adj[first].end())
            ret = true;
    }
    return ret;
}

int main() {
    int N, M;
    cin>> N >> M;
    vector<vector<int>> adj(N);

    while (M > 0)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
        M--;
    }

    int Q;
    cin>>Q;
    while (Q > 0) {
        int A, B;
        cin >> A >> B;
        if (is_existed(make_pair(A, B), adj))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        Q--;
    }
    return 0;
}