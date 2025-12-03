#include <bits/stdc++.h>
using namespace std;
using Node = pair<int,int>;

int main() {
  int N, K, M;
  if (!(cin >> N >> K >> M)) return 0;

  vector<vector<pair<int,int>>> adj(N + 1);
  for (int i = 0; i < M; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
  }

  vector<int> dist(N + 1, INT_MAX);
  priority_queue<Node, vector<Node>, greater<Node>> pq;

  dist[K] = 0;
  pq.push({0, K});

  while (!pq.empty()) {
    int d = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (d != dist[u]) continue;

    for (auto &e : adj[u]) {
      int v = e.first;
      int w = e.second;
      int nd;
      if (d > INT_MAX - w) nd = INT_MAX;
      else nd = d + w;
      if (nd >= dist[v]) continue;

      dist[v] = nd;
      pq.push({nd, v});
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; ++i) {
    if (dist[i] == INT_MAX) {
      cout << -1 << endl;
      return 0;
    }
    ans = max(ans, dist[i]);
  }

  cout << ans << endl;
  return 0;
}
