#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> t(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
  }

  vector<bool> visited(n+1);
  vector<int> ans(n+1);
  deque<int> path;

  int length = 0;
  auto dfs = [&](const auto& self, int node) -> void {
    path.push_back(node);
    if (visited[node]) {
      length += ans[node];
      return;
    }
    visited[node] = true;
    length++;
    self(self, t[node]);
  };

  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      length = 0;
      dfs(dfs, i);

      int dec = 1;
      while (!path.empty()) {
        int node = path.front();
        path.pop_front();
        ans[node] = length;
        if (node == path.back()) {
          dec = 0;
        }
        length -= dec;
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
