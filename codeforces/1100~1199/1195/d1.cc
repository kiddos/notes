#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;
void mod_add(i64& ans, i64 x) {
  ans += x;
  ans %= MOD;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  constexpr int MAX_POWER = 30;
  vector<i64> p10(MAX_POWER+1, 1);
  for (int i = 1; i <= MAX_POWER; ++i) {
    p10[i] = p10[i-1] * 10;
    p10[i] %= MOD;
  }

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    string s = to_string(a[i]);
    reverse(s.begin(), s.end());
    int len = s.length();
    for (int j = 0; j < len; ++j) {
      int d = s[j]-'0';
      i64 p = p10[j*2];
      mod_add(ans, (((p * d) % MOD) * n) % MOD);
    }
    for (int j = 0; j < len; ++j) {
      int d = s[j]-'0';
      i64 p = p10[j*2+1];
      mod_add(ans, (((p * d) % MOD) * n) % MOD);
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
