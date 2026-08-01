#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
constexpr int MOD = 1e9 + 7;

i64 power(i64 x, i64 n) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= MOD;
    }
    n >>= 1;
    x = (x * x) % MOD;
  }
  return ans;
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<i64> f(n+1, 1);
  for (int i = 2; i <= n; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }
  vector<i64> inv_f(n+1, 1);
  inv_f[n] = power(f[n], MOD-2);
  for (int i = n-1; i >= 1; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }

  auto C = [&](int N, int K) -> i64 {
    i64 ans = f[N];
    ans *= inv_f[K];
    ans %= MOD;
    ans *= inv_f[N-K];
    ans %= MOD;
    return ans;
  };

  map<int, int> count;
  count[-1] = 0;
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }

  auto compute_odd_ways = [&](int count) -> i64 {
    i64 ans = 0;
    for (int i = 1; i <= count; i += 2) {
      ans += C(count, i);
      ans %= MOD;
    }
    return ans;
  };

  auto compute_even_ways = [&](int count) -> i64 {
    i64 ans = 0;
    for (int i = 0; i <= count; i += 2) {
      ans += C(count, i);
      ans %= MOD;
    }
    return ans;
  };

  vector<pair<int,i64>> p(count.begin(), count.end());
  int size = p.size();
  vector<i64> dp1(size);
  vector<i64> dp2(size);
  dp1[0] = compute_even_ways(p[0].second);
  dp2[0] = 1;

  for (int i = 1; i < size; ++i) {
    i64 ways = compute_even_ways(p[i].second);
    dp1[i] = dp1[i-1] * ways;
    dp1[i] %= MOD;
    dp2[i] = dp2[i-1] * ways;
    dp2[i] %= MOD;
    if (p[i].first - p[i-1].first == 1 && p[0].second > 0) {
      i64 ways = compute_odd_ways(p[i-1].second) * compute_odd_ways(p[i].second);
      ways %= MOD;
      ways *= dp1[0];
      ways %= MOD;
      ways *= dp2[i-2];
      ways %= MOD;

      dp1[i] += ways;
      dp1[i] %= MOD;
    }
  }

  // for (int i = 0; i < size; ++i) {
  //   cout << dp[i] << " ";
  // }
  // cout << endl;

  i64 ans = dp1.back();
  cout << ans << endl;

  // map<int,int> even, odd;
  // even[0] = 1;
  // for (int i = n-1; i >= 0; --i) {
  //   map<int,int> odd2 = odd, even2 = even;
  //   for (auto [val, count] : odd) {
  //     even2[a[i] - val] += count;
  //   }
  //   for (auto [val, count] : even) {
  //     odd2[a[i] - val] += count;
  //   }
  //   even = std::move(even2);
  //   odd = std::move(odd2);
  // }
  // cout << even[0] + odd[0] << endl;
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
