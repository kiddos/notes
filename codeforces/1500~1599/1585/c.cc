#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 choose(vector<i64>& x, int k) {
  int n = x.size();
  if (n == 0) return 0;

  vector<i64> dp(n);
  deque<pair<int,i64>> d;
  d.push_back({-1, 0});
  for (int i = 0; i < n; ++i) {
    i64 add = x[i] * 2LL;
    while (!d.empty() && d.front().first < i-k) {
      d.pop_front();
    }
    dp[i] = (d.empty() ? 0 : d.front().second) + add;
    while (!d.empty() && d.back().second > dp[i]) {
      d.pop_back();
    }
    d.push_back({i, dp[i]});
  }
  // for (int i = 0; i < n; ++i) {
  //   cout << dp[i] << " ";
  // }
  // cout<< endl;
  return dp[n-1];
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];

  vector<i64> a, b;
  for (int i = 0; i < n; ++i) {
    if (x[i] > 0) {
      a.push_back(x[i]);
    } else if (x[i] < 0) {
      b.push_back(abs(x[i]));
    }
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  i64 ans = choose(a, k) + choose(b, k);
  if (!a.empty() && !b.empty()) {
    ans -= max(a.back(), b.back());
  } else if (!a.empty()) {
    ans -= a.back();
  } else if (!b.empty()) {
    ans -= b.back();
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
