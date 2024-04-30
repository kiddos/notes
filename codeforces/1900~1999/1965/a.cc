#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());
  a.resize(unique(a.begin(), a.end()) - a.begin());

  vector<int> ks = {a[0]};
  for (int i = 1; i < (int)a.size(); ++i) {
    ks.push_back(a[i] - a[i-1]);
  }

  int m = ks.size();
  // for (int i = 0; i < m; ++i) {
  //   cout << ks[i] << " ";
  // }
  // cout << endl;

  vector<vector<int>> memo(n, vector<int>(2, -1));
  function<bool(int,int)> dp = [&](int i, int one_left) -> bool {
    if (i >= m) {
      return false;
    }
    if (memo[i][one_left] >= 0) {
      return memo[i][one_left];
    }
    bool ans = !dp(i+1, 0);
    if (ks[i] > 1 && !one_left) {
      ans = ans || !dp(i, 1);
    }
    return memo[i][one_left] = ans;
  };

  bool ans = dp(0, 0);
  if (ans) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
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
