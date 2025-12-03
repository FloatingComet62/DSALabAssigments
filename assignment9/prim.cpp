#include <bits/stdc++.h>
using namespace std;

class Graph {
  int n;
  vector<vector<pair<int,long long>>> adj;
public:
  Graph(int nodes): n(nodes), adj(nodes+1) {}
  void addEdge(int u, int v, long long w){
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }
  pair<long long, vector<tuple<int,int,long long>>> primMST(){
    vector<char> used(n+1, 0);
    vector<long long> dist(n+1, LLONG_MAX);
    vector<int> parent(n+1, -1);
    using P = pair<long long,int>;
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[1] = 0;
    pq.push({0,1});
    long long total = 0;
    vector<tuple<int,int,long long>> mst;

    while (!pq.empty()) {
      auto cur = pq.top(); pq.pop();
      long long d = cur.first;
      int u = cur.second;
      if (used[u]) continue;
      used[u] = 1;
      if (parent[u] != -1) {
        mst.emplace_back(parent[u], u, d);
        total += d;
      }
      for(const auto &pr : adj[u]) {
        int v = pr.first;
        long long w = pr.second;
        if(used[v] || w >= dist[v]) continue;
        dist[v] = w;
        parent[v] = u;
        pq.push({dist[v], v});
      }
    }

    int visitedCount = 0;
    for (int i = 1; i <= n; i++) if(used[i]) visitedCount++;
    if (visitedCount != n) return {-1, {}};
    return {total, mst};
  }
};

int main() {
  int n, m;
  if (!(cin >> n >> m)) return 0;
  Graph g(n);
  for(int i=0;i<m;i++) {
      int u,v;
      long long w;
      cin >> u >> v >> w;
      g.addEdge(u,v,w);
  }
  auto res = g.primMST();
  if (res.first == -1) {
      cout << "IMPOSSIBLE\n";
      return 0;
  }
  cout << res.first << "\n";
  for (const auto &t : res.second) {
      int u,v; long long w;
      tie(u,v,w) = t;
      cout << u << " " << v << " " << w << "\n";
  }
  return 0;
}
