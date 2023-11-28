#include <iostream>
#include <fstream>

#include <vector>
#include <string>

#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
    friend ostream &operator<<( ostream &output, const Edge &e ) { 
        output << "u: " << e.u << " v: " << e.v << " weight: " << e.weight << endl;
        return output;            
    }

    friend istream &operator>>( istream  &input, Edge &e ) { 
        input >> e.u >> e.v >> e.weight;
        return input;            
    }
};

// Reading matrix
// https://www.codeproject.com/Questions/5248550/Opening-and-reading-a-matrix-file
vector<Edge> get_edges(string file_path, char seperator) {
    vector<Edge> ret;
    ifstream file;
    file.open(file_path);
    cout << "Open file OK \n";
    if (!file.is_open()) {
        return ret;
    }

    while(!file.eof()) {
        string row;
        getline(file, row);
        vector<int> row_vec;
        string row_value = "";

        for (char c : row) {
            //cout << "row value: " << row_value << " and c: " << c << endl;
            if (c == seperator) {
                row_vec.push_back(stoi(row_value));
                row_value = "";
            } else {
                row_value += c;
            }
        }

        if(row_value.size() != 0) {
            //cout << "row_vec size: " << row_vec.size() << endl;
            row_vec.push_back(stoi(row_value));
            ret.push_back({row_vec[0], row_vec[1], row_vec[2]});
            row_value = "";
        }
    }

    file.close();
    return ret;
}

vector<Edge> kruskal(vector<Edge> edges) {
    vector<Edge> ret;
    int cost = 0;
    vector<int> tree_id(edges.size());
    for (auto i =  0; i < edges.size(); ++i) {
        tree_id[i] = i;
    }

    sort(edges.begin(), edges.end());

    for (auto e : edges) {
        if (tree_id[e.u] != tree_id[e.v]) {
            cost += e.weight;
            ret.push_back(e);

            int old_id = tree_id[e.u];
            int new_id = tree_id[e.v];
            for (int i = 0; i < edges.size(); ++i) {
                if (tree_id[i] == old_id) {
                    tree_id[i] = new_id;
                }
            }
        }
    }
    return ret;
}

int main () {
    // getting graph from file
    vector<Edge> edges = get_edges("./data", ' ');

    vector<Edge> ret = kruskal(edges);
    for (auto e : ret)
        cout << e;

    return 0;
}