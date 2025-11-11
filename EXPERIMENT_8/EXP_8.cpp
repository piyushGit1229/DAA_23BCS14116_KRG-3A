// piyush kumar varma uid 23bcs14116

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra(int V, const vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        int d = curr.first;
        int u = curr.second;

        if (d > dist[u])
            continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex\tDistance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t" << dist[i] << endl;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<pair<int, int>>> adj(V);
    cout << "Enter edges (u v w):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int src;
    cout << "Enter source vertex: ";
    cin >> src;

    dijkstra(V, adj, src);

    return 0;
}
