#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 200000;
constexpr int MOD = 1e9 + 7;
vector<i64> f(MAX_N+1, 1);
vector<i64> inv_f(MAX_N+1, 1);

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

void precompute() {
  for (int i = 2; i <= MAX_N; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }

  inv_f[MAX_N] = power(f[MAX_N], MOD-2);
  for (int i = MAX_N-1; i >= 1; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }
}

i64 C(int n, int k) {
  i64 ans = f[n];
  ans *= inv_f[k];
  ans %= MOD;
  ans *= inv_f[n-k];
  ans %= MOD;
  return ans;
}

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    int l = i+m-1, r = n-1;
    int idx = -1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      if (a[mid] - a[i] <= k) {
        l = mid+1;
        idx = mid;
      } else {
        r = mid-1;
      }
    }
    if (idx >= 0) {
      i64 len = idx-i;
      if (len >= m-1) {
        ans += C(len, m-1);
        ans %= MOD;
      }
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
