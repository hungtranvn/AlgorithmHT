#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Node {
    int m_id = -1;
    vector<int> m_neighbor;

    Node(int id, vector<int> neighbor) : m_id(id), m_neighbor(neighbor){

    }
};

vector<Node> adj {
    Node(0, {2}),
    Node(1, {7}),
    Node(2, {0,3,4}),
    Node(3, {2,4}),
    Node(4, {2,3,5,6}),
    Node(5, {4,6}),
    Node(6, {4,5}),
    Node(7, {1})
};
vector<bool> visited(8, false);
vector<Node> comp;
vector<Node> modified_comp;

void DFS(Node v) {
    visited[v.m_id] = true;
    comp.push_back(v);
    for (auto u : v.m_neighbor) {
        if (!visited[u])    DFS(adj[u]);
    }
}

void iterative_DFS (Node source, vector<Node>& copy_adj, vector<bool>& modified_visited) {
    stack<Node> s;

    s.push(source);
    modified_visited[source.m_id] = true;

    while(!s.empty()) {
        Node v = s.top();
        s.pop();
        modified_comp.push_back(v);
        for (auto w : v.m_neighbor) {
            if (!modified_visited[w]) {
                s.push(copy_adj[w]);
                modified_visited[w] = true;
            }
        }
    }
}

int main () {
    int count = 0;
    for (auto v = 0; v < adj.size(); ++v) {
        if (!visited[v]) {
            comp.clear();
            DFS(adj[v]);
            cout << "Component: ";
            for (auto u : comp)
                cout << u.m_id;
            cout << endl;
            count++;
        }
    }
    cout << "number of connected component: " << count << endl;
    cout << "STARTING TO ANALYSIS!" << endl << endl;
    for (auto i = 0; i < adj.size(); ++i) {
        cout << "remove node: " << i << endl;
        vector<bool> modified_visited(7, false);
        int modified_count = 0;
        vector<Node> copy_adj;
        cout << "consider the graph: ";
        for (auto j = 0; j < adj.size(); ++j) {
            if (j != i) {
                copy_adj.push_back(adj[j]);
                cout << adj[j].m_id;
            }
        }
        cout << endl;
        for (auto v = 0; v < copy_adj.size(); ++v) {
            if (!modified_visited[v]) {
                modified_comp.clear();
                iterative_DFS(copy_adj[v], copy_adj, modified_visited);
                cout << "Component: ";
                for (auto u : modified_comp)
                    cout << u.m_id;
                cout << endl;
                modified_count++;
            }
        }
        cout << "Connected component count: " << modified_count << endl << endl;
    }
    
    return 0;
}