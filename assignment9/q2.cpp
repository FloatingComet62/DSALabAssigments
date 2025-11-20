#include "graph.hpp"
#include <iostream>
#include <climits>
#include <stack>

int main() {
  int m = 3, n = 3;
  std::vector<std::vector<int>> grid = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
  };
  std::vector<int> flat_grid = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  Graph g(m * n);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::vector<int> direction = {};
      if (i != m - 1) {
        direction.push_back(grid[i + 1][j]);
      }
      if (j != n - 1) {
        direction.push_back(grid[i][j + 1]);
      }
      for (auto item : direction) {
        g.addEdge(grid[i][j] - 1, item - 1, 1);
      }
    }
  }

  std::vector<int> dist;
  for (int i = 0; i < m * n; i++) {
    dist.push_back(INT_MAX);
  }

  int source = 0, destination = m * n - 1;
  dist[source] = 0;

  std::stack<std::vector<int>> s;
  s.push({source, flat_grid[source]});

  while (!s.empty()) {
    auto item = s.top();
    s.pop();

    for (int i = 0; i < g.number_of_nodes; i++) {
      if (g.getEdge(item[0], i) == 0.0) continue;
      if (dist[i] > item[1] + flat_grid[i]) {
        dist[i] = item[1] + flat_grid[i];
      }
      s.push({i, item[1] + flat_grid[i]});
    }
  }

  std::cout << dist[destination] << "\n";
}
