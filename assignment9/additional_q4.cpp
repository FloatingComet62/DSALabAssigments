#include <bits/stdc++.h>
using namespace std;

int m, n;
vector<vector<int>> grid;
vector<vector<int>> vis;

void dfs(int r, int c) {
  vis[r][c] = 1;

  int dr[4] = {1, -1, 0, 0};
  int dc[4] = {0, 0, 1, -1};

  for (int k = 0; k < 4; k++) {
    int nr = r + dr[k];
    int nc = c + dc[k];

    if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
    if (vis[nr][nc] || grid[nr][nc] != 1) continue;
    dfs(nr, nc);
  }
}

int main() {
  cin >> m >> n;

  grid.assign(m, vector<int>(n));
  vis.assign(m, vector<int>(n, 0));

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      cin >> grid[i][j];

  int count_islands = 0;

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (vis[i][j] || grid[i][j] != 1) continue;
      count_islands++;
      dfs(i, j);
    }
  }

  cout << count_islands << endl;
  return 0;
}
