#include <bits/stdc++.h>

using namespace std;

// Shortest Path Visiting All Nodes
//
// shortest path, so think bfs

struct State {
  int current;
  int visited;
};

class Solution {
 public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    int m = 1 << n;
    const int ALL_VISITED = m - 1;
    queue<State> q;
    vector<vector<bool>> visited(m, vector<bool>(n));

    for (int node = 0; node < n; ++node) {
      q.push(State{node, 1 << node});
      visited[(1 << node)][node] = true;
    }

    int steps = 0;
    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        auto [current, v] = q.front();
        q.pop();
        if (v == ALL_VISITED) return steps;
        for (int next_node : graph[current]) {
          int v2 = v | (1 << next_node);
          if (visited[v2][next_node]) continue;
          visited[v2][next_node] = true;
          q.push(State{next_node, v2});
        }
      }
      steps++;
    }
    return -1;
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  vector<vector<int>> graph = {{1, 2, 3}, {0}, {0}, {0}};
  int ans = Solution().shortestPathLength(graph);
  assert(ans == 4);

  graph = {{1}, {0, 2, 4}, {1, 3, 4}, {2}, {1, 2}};
  ans = Solution().shortestPathLength(graph);
  assert(ans == 4);
  return 0;
}
