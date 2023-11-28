#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int source, const vector<vector<int>>& adj) {
    vector<bool> visit(adj.size(), false);
    queue<int> q;
    
    q.push(source);
    visit[source] = true;
    while(!q.empty()) {
        int v = q.front();
        cout << "visited node: " << v << endl;
        q.pop();
        for(auto w : adj[v]) {
            if (!visit[w]) {
                q.push(w);
                visit[w] = true;
            }
        }
    }
}


int main() {
    int nodes, edges;
    cout << "Enter the number of nodes and number of adges: ";
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
    BFS(source, adj);

    return 0;
}