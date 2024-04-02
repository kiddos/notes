#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  i64 max_sub = 0;
  i64 current = 0;
  for (int i = 0; i < n; ++i) {
    current = max(a[i], current + a[i]);
    max_sub = max(max_sub, current);
  }

  // cout << "max sub = " << max_sub << endl;
  i64 sum = accumulate(a.begin(), a.end(), 0LL);
  sum = ((sum % MOD) + MOD) % MOD;
  for (int i = 0; i < k; ++i) {
    sum += max_sub;
    sum %= MOD;
    max_sub *= 2;
    max_sub %= MOD;
  }

  cout << sum << endl;
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
