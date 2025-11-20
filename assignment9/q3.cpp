#include "graph.hpp"

int main() {
  int n = 4;
  int k = 2;
  std::vector<std::vector<int>> times = {
    {2, 1, 1},
    {2, 3, 1},
    {3, 4, 1},
  };

  Graph g(n);
  for (auto time : times) {
    g.addEdge(time[0] - 1, time[1] - 1, time[2]);
  }
}
