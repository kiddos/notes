#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, d12 = 0, d23 = 0, d31 = 0;
  cin >> n >> d12 >> d23 >> d31;

  if ((d12 + d31 - d23) % 2 == 1) {
    cout << "NO" << endl;
    return;
  }
  int d[3];
  d[0] = (d12 + d31 - d23) / 2;

  if ((d12 + d23 - d31) % 2 == 1) {
    cout << "NO" << endl;
    return;
  }
  d[1] = (d12 + d23 - d31) / 2;

  if ((d31 + d23 - d12) % 2 == 1) {
    cout << "NO" << endl;
    return;
  }
  d[2] = (d31 + d23 - d12) / 2;

  if (d[0] < 0 || d[1] < 0 || d[2] < 0 || d[0] > n || d[1] > n || d[2] > n) {
    cout << "NO" << endl;
    return;
  }

  if (d[0] + d[1] + d[2] >= n) {
    cout << "NO" << endl;
    return;
  }

  int root = n;
  int next_node = n-1;
  for (int i = 0; i < 3; ++i) if (d[i] == 0) {
    root = i+1;
    next_node = n;
  }

  vector<pair<int,int>> edge;
  for (int i = 0; i < 3; ++i) {
    if (d[i] == 0) continue;

    int node1 = root;
    while (d[i]-- > 1) {
      int new_node = next_node--;
      edge.push_back({node1, new_node});
      node1 = new_node;
    }
    edge.push_back({node1, i+1});
  }

  int node1 = root;
  while (next_node > 3) {
    int node2 = next_node--;
    edge.push_back({node1, node2});
    node1 = node2;
  }

  // cout << d[0] << "," << d[1] << ", " << d[2] << endl;
  cout << "YES" << endl;
  for (auto& [u, v] : edge) {
    cout << u << " " << v << endl;
  }
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
