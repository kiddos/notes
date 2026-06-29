#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<vector<int>> a(n+1, vector<int>(2));
  for (int i = 1; i <= n; ++i) {
    cin >> a[i][0] >> a[i][1];
  }

  auto has_next_node = [&](int node, int other_node) -> bool {
    for (int next_node : a[node]) {
      if (next_node == other_node) {
        return true;
      }
    }
    return false;
  };

  int node = 1;
  vector<int> ans = {};
  vector<bool> used(n+1);
  for (int i = 0; i < n; ++i) {
    ans.push_back(node);
    used[node] = true;
    vector<int>& possible = a[node];
    for (int k = 0; k < 2; ++k) {
      int next_node = possible[k];
      int other_next_node = possible[1-k];
      if (used[next_node]) {
        continue;
      }
      if (!has_next_node(next_node, other_next_node)) {
        continue;
      }
      node = next_node;
      break;
    }
  }

  for (int i = 0; i < n; ++i) {
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
