#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> b(n+1);
  for (int i = 1; i <= n; ++i) cin >> b[i];

  if (k == 1) {
    for (int i = 1; i <= n; ++i) {
      if (b[i] != i) {
        cout << "NO" << endl;
        return;
      }
    }
    cout << "YES" << endl;
    return;
  }

  int id = 1;
  vector<int> ids(n+1);
  vector<int> time(n+1);
  auto bfs = [&](int start) -> int {
    if (ids[start]) return ids[start];

    queue<pair<int,int>> q({{start, 1}});
    time[start] = 1;
    ids[start] = id++;

    while (!q.empty()) {
      for (int size = q.size(); size > 0; --size) {
        auto [node, t] = q.front();
        q.pop();

        int next_node = b[node];
        if (ids[next_node]) {
          if (ids[next_node] != ids[start]) {
            return -1;
          }
          return t - time[next_node] + 1;
        }

        q.push({next_node, t+1});
        time[next_node] = t+1;
        ids[next_node] = ids[start];
      }
    }
    return -1;
  };

  for (int i = 1; i <= n; ++i) {
    if (!ids[i]) {
      int cycle = bfs(i);
      // cout << "cycle: " << cycle << endl;
      if (cycle > 0 && cycle != k) {
        cout << "NO" << endl;
        return;
      }
    }
  }
  cout << "YES" << endl;
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
