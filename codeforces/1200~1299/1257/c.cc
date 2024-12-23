#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<int, vector<int>> indices;
  for (int i = 0; i < n; ++i) {
    indices[a[i]].push_back(i);
  }
  int ans = numeric_limits<int>::max();
  for (auto& [x, idx] : indices) {
    if (idx.size() >= 2) {
      for (int i = 1; i < (int)idx.size(); ++i) {
        int len = idx[i] - idx[i-1] + 1;
        ans = min(ans, len);
      }
    }
  }

  if (ans == numeric_limits<int>::max()) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
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
