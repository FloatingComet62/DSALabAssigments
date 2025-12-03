#include <bits/stdc++.h>
using namespace std;

int main() {
  int V, E;
  if (!(cin >> V >> E)) return 0;
  vector<vector<int>> adj(V);
  for (int i = 0; i < E; ++i) {
    int u, v;
    cin >> u >> v;
    if(u >= 0 && u < V && v >= 0 && v < V) {
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
  }

  vector<char> visited(V, 0);
  int components = 0;

  for(int i = 0; i < V; ++i) {
    if (visited[i]) continue;
    ++components;
    queue<int> q;
    q.push(i);
    visited[i] = 1;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for(int w : adj[u]) {
        if(visited[w]) continue;
        visited[w] = 1;
        q.push(w);
      }
    }
  }

  cout << components << "\n";
  return 0;
}
