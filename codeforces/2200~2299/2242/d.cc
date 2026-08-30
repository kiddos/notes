#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string a, b;
  cin >> a >> b;

  auto compute_mods = [&](string& s) -> vector<int> {
    int n = s.length();
    vector<int> mod(n);
    for (int i = 0, m = 0; i < n; ++i) {
      m += (s[i]-'0');
      m %= 10;
      mod[i] = m;
    }
    return mod;
  };

  vector<int> mod_a = compute_mods(a);
  vector<int> mod_b = compute_mods(b);

  if (mod_a.back() != mod_b.back()) {
    cout << "-1" << endl;
    return;
  }

  int n = a.length();
  vector<vector<int>> indices(10);
  for (int i = 0; i < n; ++i) {
    indices[mod_a[i]].push_back(i);
  }

  int m = b.length();
  vector<int> dp(n);
  for (int j = 0; j < m; ++j) {
    vector<int> dp2 = dp;
    for (int i : indices[mod_b[j]]) {
      dp2[i] = max(dp2[i], i > 0 ? dp[i-1] + 1 : 1);
    }
    for (int i = 1; i < n; ++i) {
      dp2[i] = max(dp2[i], dp2[i-1]);
    }
    dp = std::move(dp2);
  }

  int ans = dp[n-1];
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
