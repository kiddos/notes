#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  vector<i64> p10(n+1, 1);
  for (int i = 1; i <= n; ++i) {
    p10[i] = p10[i-1] * 10;
    p10[i] %= MOD;
  }

  vector<i64> prefix(n+1);
  for (int r = 0; r <= n; ++r) {
    prefix[r] = p10[r] * (r+1);
    prefix[r] %= MOD;
  }

  for  (int i = 1; i <= n; ++i) {
    prefix[i] += prefix[i-1];
  }

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    i64 d = s[i] - '0';
    i64 left_digits = i;
    i64 right_digits = n-i-1;
    i64 left_total = (left_digits + 1) * left_digits / 2;
    left_total %= MOD;

    ans += (((d * left_total) % MOD) * p10[right_digits]) % MOD;
    ans %= MOD;
    if (right_digits > 0) {
      ans += (prefix[right_digits-1] * d) % MOD;
      ans %= MOD;
    }
    // for (int remove = 1; remove <= right_digits; ++remove) {
    //   i64 right = right_digits - remove;
    //   i64 ways = right_digits - remove + 1;
    //   ans += ((p10[right] * ways) % MOD) * d;
    //   ans %= MOD;
    // } 
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
