#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  map<int, i64> index;
  int balance = 0;
  i64 ans = 0;
  constexpr int MOD = 1000000007;
  for (int i = 0; i < n; ++i) {
    i64 rest = n - i + 1;
    if (index.count(balance)) {
      ans += index[balance] * rest;
      ans %= MOD;
    }
    index[balance] += (i+1);
    index[balance] %= MOD;
    // cout << "i=" << i << ", balance=" << balance<< ", index sum=" << index[balance] << endl;

    if (s[i] == '1') {
      balance++;
    } else if (s[i] == '0') {
      balance--;
    }
  }
  ans += index[balance];
  ans %= MOD;

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
