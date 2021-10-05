#include <bits/stdc++.h>

using namespace std;

struct Node {
  int id;
  unordered_set<int> neighbor;
};

vector<int> welsh_powell(vector<Node>& graph) {
  int n = graph.size();
  vector<int> colors(n);

  sort(graph.begin(), graph.end(), [&](auto& n1, auto& n2) {
    return n1.neighbor.size() > n2.neighbor.size();
  });

  for (int color = 1; color <= 5; ++color) {
    for (int i = 0; i < n; ++i) {
      if (!colors[graph[i].id]) {
        bool found = false;
        for (int neighbor_id : graph[i].neighbor) {
          if (colors[neighbor_id] == color) {
            found = true;
            break;
          }
        }

        if (!found) {
          colors[graph[i].id] = color;
        }
      }
    }
  }
  return colors;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // const int n = 10;
  const int n = 7;
  vector<Node> graph(n);
  // graph[0] = Node{0, {1,2,3}};
  // graph[1] = Node{1, {0,2}};
  // graph[2] = Node{2, {0,1,3,4}};
  // graph[3] = Node{3, {0,2,5}};
  // graph[4] = Node{4, {2,5,6,8}};
  // graph[5] = Node{5, {3,4,8,9}};
  // graph[6] = Node{6, {4,7}};
  // graph[7] = Node{7, {6,8}};
  // graph[8] = Node{8, {4,7,9}};
  // graph[9] = Node{9, {5,8}};
  graph[0] = Node{0, {2}};
  graph[1] = Node{1, {2,4}};
  graph[2] = Node{2, {0,1,3,4}};
  graph[3] = Node{3, {2}};
  graph[4] = Node{4, {1,2,5,6}};
  graph[5] = Node{5, {2,4,6}};
  graph[6] = Node{6, {4,5}};

  vector<int> colors = welsh_powell(graph);
  for (int i = 0; i < n; ++i) {
    cout << (char)(i+'A') << " has color: " << colors[i] << endl;
  }
  return 0;
}
