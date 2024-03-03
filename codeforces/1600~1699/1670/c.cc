#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];
  vector<int> d(n);
  for (int i = 0; i < n; ++i) cin >> d[i];

  vector<int> c = d;
  vector<vector<int>> indices(n+1);
  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) {
      indices[a[i]].push_back(i);
      indices[b[i]].push_back(i);
    } else {
      c[i] = b[i];
    }
  }

  function<void(int,int)> dfs = [&](int idx, int val) {
    for (int idx2 : indices[val]) {
      if (idx2 == idx) continue;
      if (c[idx2]) continue;
      c[idx2] = val == b[idx2] ? a[idx2] : b[idx2];
      dfs(idx2, c[idx2]);
    }
  };

  for (int i = 0; i < n; ++i) {
    if (c[i] > 0) {
      dfs(i, c[i]);
    }
  }

  constexpr int MOD = 1e9 + 7;
  i64 ans = 1;
  for (int i = 0; i < n; ++i) {
    if (c[i] == 0) {
      c[i] = a[i];
      dfs(i, c[i]);

      ans *= 2;
      ans %= MOD;
    }
  }

  cout << ans << endl;
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
