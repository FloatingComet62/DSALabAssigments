#include <iostream>
#include <vector>

class Node {
public:
  int data;
  Node* next;
  Node* prev;
  Node* up;
  Node* down;
  Node(int v) { data=v; }
};

std::vector<std::vector<Node*>> constructFromMatrix(int mat[][3], int R, int C) {
  std::vector<std::vector<Node*>> nodes(R, std::vector<Node*>(C, nullptr));

  for (int i=0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      nodes[i][j] = new Node(mat[i][j]);
    }
  }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (j + 1 < C) nodes[i][j]->next = nodes[i][j+1];
      if (j - 1 >= 0) nodes[i][j]->prev = nodes[i][j-1];
      if (i - 1 >= 0) nodes[i][j]->up = nodes[i-1][j];
      if (i + 1 < R) nodes[i][j]->down = nodes[i+1][j];
    }
  }

  return nodes;
}

void printGridLinks(const std::vector<std::vector<Node*>>& nodes, int R, int C){
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      Node* n = nodes[i][j];
      std::cout << "Node(" << n->data << ") -> ";

      std::cout << "next:";
      if (n->next) std::cout << n->next->data;
      else std::cout << "NULL";

      std::cout << ", prev:";
      if (n->prev) std::cout << n->prev->data;
      else std::cout << "NULL";

      std::cout << ", up:";
      if (n->up) std::cout << n->up->data;
      else std::cout << "NULL";

      std::cout << ", down:";
      if (n->down) std::cout << n->down->data;
      else std::cout << "NULL";

      std::cout << "\n";
    }
  }
}

int main(){
    int mat[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };

    int R = 3, C = 3;
    std::vector<std::vector<Node*>> nodes = constructFromMatrix(mat, R, C);
    printGridLinks(nodes, R, C);

    return 0;
}
