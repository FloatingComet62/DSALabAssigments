#include <bits/stdc++.h>
using namespace std;
using Node = pair<int, pair<int,int>>;

int main() {
  int m, n;
  cin >> m >> n;

  vector<vector<int>> grid(m, vector<int>(n));
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      cin >> grid[i][j];

  vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
  priority_queue<Node, vector<Node>, greater<Node>> pq;

  dist[0][0] = grid[0][0];
  pq.push({dist[0][0], {0,0}});

  int dr[4] = {-1, 1, 0, 0};
  int dc[4] = {0, 0, -1, 1};

  while (!pq.empty()) {
    int d = pq.top().first;
    int r = pq.top().second.first;
    int c = pq.top().second.second;
    pq.pop();

    if (d != dist[r][c]) continue;
    if (r == m-1 && c == n-1) break;

    for (int k = 0; k < 4; ++k) {
      int nr = r + dr[k];
      int nc = c + dc[k];
      if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
      if (dist[r][c] == INT_MAX) continue;

      int nd = d + grid[nr][nc];
      if (nd >= dist[nr][nc]) continue;
      dist[nr][nc] = nd;
      pq.push({nd, {nr, nc}});
    }
  }

  cout << dist[m-1][n-1] << "\n";
  return 0;
}
