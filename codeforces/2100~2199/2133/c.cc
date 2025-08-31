#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

int query(vector<int>& path, int x) {
  cout << "? " << x << " " << path.size();
  for (int node : path) {
    cout << " " << node;
  }
  cout << endl;

  int result = 0;
  cin >> result;
  return result;
}

void answer(vector<int>& path) {
  cout << "! " << path.size();
  for (int v : path) {
    cout << " " << v;
  }
  cout << endl;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> can_reach(n+1);
  vector<int> all_nodes(n);
  iota(all_nodes.begin(), all_nodes.end(), 1);

  for (int node = 1; node <= n; ++node) {
    can_reach[node] = query(all_nodes, node);
  }

  map<int, vector<int>> by_length;
  for (int node = 1; node <= n; ++node) {
    by_length[can_reach[node]].push_back(node);
  }

  int max_len = by_length.rbegin()->first;

  vector<int> path;
  int expected_len = 1;
  for (auto it = by_length.rbegin(); it != by_length.rend(); ++it, ++expected_len) {
    auto [len, nodes] = *it;
    if (len == max_len) {
      path.push_back(nodes[0]);
    } else {
      for (int next_node : nodes) {
        path.push_back(next_node);
        int result = query(path, path[0]);
        if (result == expected_len) {
          break;
        }
        path.pop_back();
      }
    }
  }

  answer(path);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
