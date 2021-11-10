#include <iostream>
#include <vector>

vector<int> bfs(int u, vector<vector<int> > &adj, vector<bool> &visited, vector<int> dist) {
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int temp = q.front();
        visited[temp] = true;
        cout << temp + 1 << endl;
        q.pop();
        for (auto i: adj[temp]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
                dist[i] = dist[temp] + 1;
            }
        }
    }
    return dist;
}

int main() {
    int nodes, edges, u, v;
    cin >> nodes >> edges;
    vector<vector<int> > adj(nodes);
    vector<bool> visited(nodes, false);
    vector<int> dist(nodes);
    for(int i = 0; i <= edges; ++i) {
        cin >> u >> v;
        --u, --v;       
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> distances = bfs(0, adj, visited, dist);   //assume root is always node 0
    for (int i = 0; i < nodes; i++) {
        cout << "Distance of " << i + 1 << " is " << distances[i] << endl;
    }
    return 0;
}
