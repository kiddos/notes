#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
constexpr int MOD = 998244353;

vector<int> get_factors(int x) {
  vector<int> f;
  for (int d = 2; d*d <= x; ++d) {
    if (x % d == 0) {
      f.push_back(x / d);
      f.push_back(d);
    }
  }
  sort(f.begin(), f.end());
  f.resize(unique(f.begin(), f.end()) - f.begin());
  return f;
}

i64 extended_euclidean(i64 a, i64 b, i64& x, i64& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  i64 x1 = 0, y1 = 0;
  i64 g = extended_euclidean(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}

i64 mod_inv(int b, int m) {
  i64 x = 0, y = 0;
  i64 g = extended_euclidean(b, m, x, y);
  if (g != 1) {
    return -1;
  } else {
    i64 inv_b = (x % m + m) % m;
    return inv_b;
  }
}

i64 C(i64 n, i64 k) {
  i64 ans = 1;
  i64 k1 = max(n - k, k);
  int k2 = n - k1;
  for (i64 x = n; x > k1; --x) {
    ans *= x;
    ans %= MOD;
  }
  for (int x = k2; x > 1; --x) {
    ans *= mod_inv(x, MOD);
    ans %= MOD;
  }
  // cout << "C(" << n << "," << k << ")=" << ans << endl;
  return ans;
}

void solve() {
  int k = 0, n = 0;
  cin >> k >> n;

  constexpr int max_len = 17;
  vector<vector<i64>> dp(k+1, vector<i64>(max_len+1));
  for (int y = 1; y <= k; ++y) {
    dp[y][1] = 1;
  }

  for (int x = 1; x <= k; ++x) {
    vector<int> factors = get_factors(x);
    for (int len = 2; len <= max_len; ++len) {
      for (int f : factors) {
        dp[x][len] += dp[f][len-1];
        dp[x][len] %= MOD;
      }
    }
  }

  // for (int x = 1; x <= k; ++x) {
  //   for (int len = 1; len <= min(max_len, n); ++len) {
  //     cout << dp[x][len] << " ";
  //   }
  //   cout << endl;
  // }

  vector<i64> ans(k+1);
  ans[1] = n;
  for (int x = 2; x <= k; ++x) {
    for (int len = 1; len <= min(max_len, n); ++len) {
      ans[x] += dp[x][len] * C(n+1, len+1);
      ans[x] %= MOD;
    }
  }

  for (int i = 1; i <= k; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
