#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;

i64 power(i64 x, i64 n) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= MOD;
    }
    n >>= 1;
    x = (x * x);
    x %= MOD;
  }
  return ans;
}

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  int m = n * 2;
  vector<i64> f(m+1, 1);
  for (int i = 2; i <= m; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }
  vector<i64> inv_f(m+1, 1);
  inv_f[m] = power(f[m], MOD-2);
  for (int i = m-1; i >= 1; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }

  auto C = [&](int n, int k) -> i64 {
    i64 ans = f[n];
    ans *= inv_f[n-k];
    ans %= MOD;
    ans *= inv_f[k];
    ans %= MOD;
    return ans;
  };

  vector<vector<int>> count(2, vector<int>(n+1));
  for (int i = 0; i < n; ++i) {
    int c = s[i]-'0';
    count[c][i+1]++;
  }
  for (int c = 0; c < 2; ++c) {
    for (int i = 1; i <= n; ++i) {
      count[c][i] += count[c][i-1];
    }
  }

  if (count[1][n] < k) {
    cout << "1" << endl;
    return;
  }
  
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      int c0 = count[0][j+1] - count[0][i];
      int c1 = count[1][j+1] - count[1][i];
      if (c1 <= k) {
        if (s[i] == '0') c1--;
        else c0--;
        if (s[j] == '0') c1--;
        else c0--;

        if (c0 >= 0 && c1 >= 0) {
          // cout << "c0=" << c0 << ",c1=" << c1 << endl;
          ans += C(c0 + c1, c0);
          ans %= MOD;
        }
      }
    }
  }
  ans++;
  ans %= MOD;
  cout << ans << endl;
  ans++;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
