#include <vector>
#include <iostream>

using namespace std;

class Queue {
  vector<int> data;
  int pointer;
public:
  Queue() {
    pointer = 0;
  }
  void enqueue(int item) {
    data.push_back(item);
  }
  int dequeue() {
    int target = data[pointer];
    pointer++;
    return target;
  }
  int length() {
    return data.size() - pointer;
  }
};

void bfs(vector<vector<int>> adj) {
  Queue q;
  vector<int> visited = {0, 0, 0, 0, 0};

  q.enqueue(0);
  while (q.length() != 0) {
    int item = q.dequeue();
    visited[item] = 1;
    cout << item;
    for (int i = 0; i < adj[item].size(); i++) {
      if (adj[item][i] != 0 && !visited[i]) q.enqueue(i);
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
  bfs(adj);
}

