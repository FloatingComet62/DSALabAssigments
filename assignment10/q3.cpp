#include <vector>
#include <iostream>

using namespace std;

class Stack {
  int data[100];
  int pointer;
  public:
  Stack() {
    pointer = -1;
  }
  void push(int item) {
    pointer++;
    data[pointer] = item;
  }

  int pop() {
    int target = data[pointer];
    pointer--;
    return target;
  }

  int length() {
    return pointer + 1;
  }
};

void dfs(vector<vector<int>> adj) {
  Stack q;
  vector<int> visited = {0, 0, 0, 0, 0};

  q.push(0);
  while (q.length() != 0) {
    int item = q.pop();
    visited[item] = 1;
    cout << item;
    for (int i = 0; i < adj[item].size(); i++) {
      if (adj[item][i] != 0 && !visited[i]) q.push(i);
    }
  }
}

int main() {
  vector<vector<int>> adj = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0},
    {0, 0, 1, 0, 0},
  };
  dfs(adj);
}

