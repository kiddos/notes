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

  map<int,vector<int>> indices;
  for (int i = 0; i < n; ++i) {
    indices[a[i]].push_back(i);
  }

  vector<int> memo(n, -1);
  auto dp = [&](const auto& self, int i) -> int {
    if (i == n) {
      return 0;
    }
    if (memo[i] >= 0) {
      return memo[i];
    }
    vector<int>& idx = indices[a[i]];
    int j = lower_bound(idx.begin(), idx.end(), i) - idx.begin();
    int ans = 0;
    if (j + a[i] <= (int)idx.size()) {
      int last = idx[j+a[i]-1];
      ans = max(ans, self(self, last+1) + a[i]);
    }
    ans = max(ans, self(self, i+1));
    return memo[i] = ans;
  };

  int ans = dp(dp, 0);
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
