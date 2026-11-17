#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<int> adj[], vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";

    for (int v: adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[20];
    cout << "Enter " << E << " edges (u v):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    vector<bool> visited(V, false);
    cout << "DFS Traversal: ";
    dfs(start, adj, visited);
    cout << endl;

    return 0;
}
