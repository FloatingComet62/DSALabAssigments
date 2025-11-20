#include <vector>

class Graph {
public:
  int number_of_nodes;
  std::vector<float> edges;

  Graph(int number_of_nodes) {
    this->number_of_nodes = number_of_nodes;
    this->edges.reserve(number_of_nodes * number_of_nodes);
    for (int i = 0; i < number_of_nodes * number_of_nodes; i++) {
      edges[i] = 0.0;
    }
  }

  void addEdge(int from, int to, float weight) {
    this->edges[from * number_of_nodes + to] = weight;
  }

  void addBidirectionalEdge(int p1, int p2, float weight) {
    this->addEdge(p1, p2, weight);
    this->addEdge(p2, p1, weight);
  }

  float getEdge(int from, int to) {
    return this->edges[from * number_of_nodes + to];
  }
};
