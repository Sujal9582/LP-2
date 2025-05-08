#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int find(vector<int>& parent, int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = find(parent, parent[node]);
}

void unionSet(vector<int>& parent, vector<int>& rank, int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);

    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV])
            parent[rootU] = rootV;
        else if (rank[rootU] > rank[rootV])
            parent[rootV] = rootU;
        else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare);
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;
    vector<Edge> mst;

    for (Edge edge : edges) {
        if (find(parent, edge.u) != find(parent, edge.v)) {
            mst.push_back(edge);
            unionSet(parent, rank, edge.u, edge.v);
        }
    }

    cout << "\nEdges in the Minimum Spanning Tree:\n";
    for (Edge edge : mst)
        cout << edge.u << " -- " << edge.v << " == " << edge.weight << endl;
}

int main() {
    int n, e;
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    vector<Edge> edges(e);
    cout << "Enter " << e << " edges (u v weight):\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    kruskal(n, edges);

    return 0;
}
