#include "graph.hpp"
#include <iostream>

void dfs(Graph& g, std::vector<bool>& visited, int root_idx) {
  visited[root_idx] = true;

  for (int i = 0; i < g.number_of_nodes; i++) {
    if (visited[i]) continue;
    if (g.getEdge(root_idx, i) <= 0.0) continue;
    dfs(g, visited, i);
  }
}

int get_visitation_target(std::vector<bool> visited) {
  for (int i = 0; i < visited.size(); i++) {
    if (visited[i]) continue;
    return i;
  }
  return -1;
}

int main() {
  int n = 5;
  std::vector<std::vector<int>> edges = {
    {0, 1},
    {1, 2},
    {3, 4}
  };

  Graph g(5);
  for (auto edge : edges) {
    g.addBidirectionalEdge(edge[0], edge[1], 1.0);
  }

  std::vector<bool> visited;
  for (int i = 0; i < n; i++) {
    visited.push_back(false);
  }
  int counter = 0;
  do {
    int target = get_visitation_target(visited);
    if (target == -1) break;
    dfs(g, visited, target);
    counter++;
  } while (true);
  std::cout << counter << "\n";
}
