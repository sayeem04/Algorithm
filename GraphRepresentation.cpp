#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

using ll = long long;
const ll INF = (1LL << 60);
using Graph = vector<vector<pair<int, int>>>;

void addEdge(Graph &adj, vector<vector<ll> > &matrix,
             vector<vector<int> > &edges,
             int u, int v, int weight) {
    adj[u].push_back({v, weight});
    adj[v].push_back({u, weight});
    matrix[u][v] = min(matrix[u][v], (ll) weight);
    matrix[v][u] = min(matrix[v][u], (ll) weight);
    edges.push_back({weight, u, v});
}

void printList(const Graph &adj) {
    for (int u = 0; u < (int) adj.size(); u++) {
        cout << u << ": ";
        for (auto edge: adj[u]) {
            cout << "(" << edge.first << ", "
                    << edge.second << ") ";
        }
        cout << '\n';
    }
}

void printMatrix(const vector<vector<ll> > &matrix) {
    for (auto row: matrix) {
        for (ll value: row) {
            if (value == INF) cout << "INF ";
            else cout << value << " ";
        }
        cout << '\n';
    }
}

void bfs(const Graph &adj, int start) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto edge: adj[u]) {
            int v = edge.first;
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << '\n';
}

void dfsVisit(const Graph &adj, int u,
              vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";
    for (auto edge: adj[u]) {
        int v = edge.first;
        if (!visited[v]) {
            dfsVisit(adj, v, visited);
        }
    }
}

void dfs(const Graph &adj, int start) {
    vector<bool> visited(adj.size(), false);
    dfsVisit(adj, start, visited);
    cout << '\n';
}

vector<ll> dijkstra(const Graph &adj, int source) {
    int n = adj.size();
    vector<ll> dist(n, INF);
    vector<bool> used(n, false);
    dist[source] = 0;
    for (int step = 0; step < n; step++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!used[v] &&
                (u == -1 || dist[v] < dist[u])) {
                u = v;
            }
        }
        if (u == -1 || dist[u] == INF) break;
        used[u] = true;
        for (auto edge: adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }
    return dist;
}

ll prim(const Graph &adj) {
    int n = adj.size();
    vector<ll> key(n, INF);
    vector<bool> inTree(n, false);
    key[0] = 0;
    ll total = 0;

    for (int step = 0; step < n; step++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!inTree[v] &&
                (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }
        if (u == -1 || key[u] == INF) return INF;
        inTree[u] = true;
        total += key[u];

        for (auto edge: adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            if (!inTree[v] && weight < key[v]) {
                key[v] = weight;
            }
        }
    }
    return total;
}

int findRoot(int u, vector<int> &parent) {
    if (parent[u] == u) return u;
    parent[u] = findRoot(parent[u], parent);
    return parent[u];
}

bool unite(int u, int v, vector<int> &parent,
           vector<int> &groupSize) {
    int rootU = findRoot(u, parent);
    int rootV = findRoot(v, parent);
    if (rootU == rootV) return false;
    if (groupSize[rootU] < groupSize[rootV]) {
        swap(rootU, rootV);
    }
    parent[rootV] = rootU;
    groupSize[rootU] += groupSize[rootV];
    return true;
}

ll kruskal(int n, vector<vector<int> > edges) {
    sort(edges.begin(), edges.end());
    vector<int> parent(n);
    vector<int> groupSize(n, 1);

    for (int i = 0; i < n; i++) parent[i] = i;
    ll total = 0;
    int taken = 0;

    for (auto edge: edges) {
        int weight = edge[0];
        int u = edge[1];
        int v = edge[2];
        if (unite(u, v, parent, groupSize)) {
            total += weight;
            taken++;
            if (taken == n - 1) break;
        }
    }
    if (taken != n - 1) return INF;
    return total;
}

vector<vector<ll> > floydWarshall(
    vector<vector<ll> > dist) {
    int n = dist.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF &&
                    dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j],
                                     dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist;
}


int main() {

    int n, m;
    cin >> n >> m;
    if (n <= 0 || m < 0) return 0;
    Graph adj(n);
    vector<vector<ll> > matrix(n, vector<ll>(n, INF));
    for (int i = 0; i < n; i++) matrix[i][i] = 0;
    vector<vector<int> > edges;
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        if (u < 0 || u >= n || v < 0 || v >= n ||
            weight < 0) {
            cout << "Invalid vertex or negative weight\n";
            return 0;
            }
        addEdge(adj, matrix, edges, u, v, weight);
    }
    int source;
    cin >> source;
    if (source < 0 || source >= n) return 0;
    cout << "Adjacency list:\n";
    printList(adj);
    cout << "Adjacency matrix:\n";
    printMatrix(matrix);
    cout << "BFS: ";
    bfs(adj, source);
    cout << "DFS: ";
    dfs(adj, source);


    vector<ll> dist = dijkstra(adj, source);
    cout << "Dijkstra distances:\n";
    for (int v = 0; v < n; v++) {
        cout << source << " -> " << v << ": ";
        if (dist[v] == INF) cout << "Unreachable\n";
        else cout << dist[v] << '\n';
    }
    ll primCost = prim(adj);
    if (primCost == INF) cout << "Prim: No MST\n";
    else cout << "Prim MST weight: " << primCost << '\n';
    ll kruskalCost = kruskal(n, edges);
    if (kruskalCost == INF) cout << "Kruskal: No MST\n";
    else cout << "Kruskal MST weight: "
    << kruskalCost << '\n';
    cout << "Floyd Warshall distances:\n";
    printMatrix(floydWarshall(matrix));
    return 0;
}
/*
Inputs :
5 6
0 1 2
0 2 4
1 2 1
1 3 7
2 4 3
3 4 2
0


Output :

Adjacency list:
0: (1, 3) (2, 4)
1: (0, 3) (2, 1) (3, 7)
2: (0, 4) (1, 1) (4, 3)
3: (1, 7) (4, 2)
4: (2, 3) (3, 2)
Adjacency matrix:
0 3 4 INF INF
3 0 1 7 INF
4 1 0 INF 3
INF 7 INF 0 2
INF INF 3 2 0
BFS: 0 1 2 3 4
DFS: 0 1 2 4 3
Dijkstra distances:
0 -> 0: 0
0 -> 1: 3
0 -> 2: 4
0 -> 3: 9
0 -> 4: 7
Prim MST weight: 9
Kruskal MST weight: 9
Floyd Warshall distances:
0 3 4 9 7
3 0 1 6 4
4 1 0 5 3
9 6 5 0 2
7 4 3 2 0

Process finished with exit code 0













*/
