#include <vector>
#include <iostream>
#include <algorithm>

class Edge {
public:
    int u;
    int v;
    long long w;
    Edge(int uu = 0, int vv = 0, long long ww = 0) {
      u = uu;
      v = vv;
      w = ww;
    }
};

class DisjointSet {
  std::vector<int> parent;
  std::vector<int> rankv;
public:
  DisjointSet(int n): parent(n+1), rankv(n+1,0) {
    for (int i = 1; i <= n; i++) parent[i]=i;
  }
  int find(int x) {
    while(parent[x] != x) x = parent[x];
    return x;
  }
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (rankv[a] < rankv[b]) std::swap(a,b);
    parent[b] = a;
    if (rankv[a] == rankv[b]) rankv[a] ++;
    return true;
  }
};

class KruskalMST {
  int n;
  std::vector<Edge> edges;
public:
  KruskalMST(int nodes): n(nodes) {}
  void addEdge(int u, int v, long long w) { edges.emplace_back(u,v,w); }
  std::pair<long long, std::vector<Edge>> build() {
    std::sort(
      edges.begin(),
      edges.end(),
      [](const Edge& a, const Edge& b) {
        if(a.w != b.w) return a.w < b.w;
        if(a.u != b.u) return a.u < b.u;
        return a.v < b.v;
    });
    DisjointSet dsu(n);
    std::vector<Edge> mst;
    long long total = 0;
    for (const Edge& e : edges) {
      if (!dsu.unite(e.u, e.v)) continue;
      mst.push_back(e);
      total += e.w;
      if (mst.size() == n-1) break;
    }
    if (mst.size() != n-1) return {-1, {}};
    return {total, mst};
  }
};

int main() {
  int n, m;
  if(!(std::cin >> n >> m)) return 0;
  KruskalMST solver(n);
  for (int i = 0; i < m; i++) {
      int u,v;
      long long w;
      std::cin >> u >> v >> w;
      solver.addEdge(u,v,w);
  }
  auto res = solver.build();
  if (res.first == -1) {
    std::cout << "IMPOSSIBLE\n";
      return 0;
  }
  std::cout << res.first << "\n";
  for (const Edge& e : res.second)
    std::cout << e.u << " " << e.v << " " << e.w << "\n";
  return 0;
}
