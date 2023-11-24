#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS (int source, const vector<vector<int>>& adj) {
    vector<bool> visit(adj.size(), false);
    stack<int> s;

    s.push(source);
    visit[source] = true;
    while(!s.empty()) {
        int v = s.top();
        cout << "visited node: " << v << endl;
        s.pop();
        for (auto w : adj[v]) {
            if (!visit[w]) {
                s.push(w);
                visit[w] = true;
            }
        }
    }
}

void DFS_recursive (int source, const vector<vector<int>>& adj, vector<bool>& visit) {
    visit[source] = true;
    cout << "visited node: " << source << endl;
    for (auto w : adj[source]) {
        if (!visit[w])
           DFS_recursive(w, adj, visit); 
    }
}

int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and the number of adges: ";
    cin >> nodes >> edges;

    vector<vector<int>> adj(nodes);
    
    while (edges > 0) {
        int A, B;
        cout << "Enter the edge A--B:";
        cin >> A >> B;
        adj[A].push_back(B);
        edges--;
    }

    int source;
    cout << "Enter source: ";
    cin >> source;
    DFS(source, adj);

    cout << "DFS recurvive \n";
    vector<bool> visit(adj.size(), false);
    DFS_recursive(source, adj, visit);
    return 0;
}