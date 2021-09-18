#include <bits/stdc++.h>

using namespace std;

// Cheapest Flights Within K Stops
//
// dijkstra solution

struct Node {
  int node;
  int dist;
  int stop;
};

struct Compare {
  bool operator()(const Node& n1, const Node& n2) {
    if (n1.stop == n2.stop) {
      return n1.dist > n2.dist;
    }
    return n1.stop > n2.stop;
  }
};

class Solution {
 public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                        int K) {
    vector<vector<pair<int, int>>> adj(n);
    for (vector<int>& flight : flights) {
      adj[flight[0]].push_back({flight[1], flight[2]});
    }

    vector<int> dist(n, numeric_limits<int>::max());
    priority_queue<Node, vector<Node>, Compare> pq;
    dist[src] = 0;
    pq.push(Node{src, 0, 0});
    while (!pq.empty()) {
      Node node = pq.top();
      pq.pop();

      for (pair<int, int>& next_node : adj[node.node]) {
        int new_dist = node.dist + next_node.second;
        if (new_dist < dist[next_node.first] && node.stop <= K) {
          dist[next_node.first] = new_dist;
          pq.push(Node{next_node.first, new_dist, node.stop + 1});
        }
      }
    }
    if (dist[dst] == numeric_limits<int>::max()) return -1;
    return dist[dst];
  }
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 5;
  vector<vector<int>> flights = {{0, 1, 5}, {1, 2, 5}, {0, 3, 2},
                                 {3, 1, 2}, {1, 4, 1}, {4, 2, 1}};
  int src = 0;
  int dst = 2;
  int k = 2;

  int ans = Solution().findCheapestPrice(n, flights, src, dst, k);
  assert(ans == 7);

  return 0;
}
