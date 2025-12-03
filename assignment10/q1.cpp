#include <cstdio>

int main() {
  int adj[5][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
  };

  int target = 2;
  int in_degree = 0;
  int out_degree = 0;
  for (int i = 0; i < 5; i++) {
    if (adj[i][target] != 0) in_degree++;
    if (adj[target][i] != 0) out_degree++;
  }
  printf("%d %d", in_degree, out_degree);

  return 0;
}
