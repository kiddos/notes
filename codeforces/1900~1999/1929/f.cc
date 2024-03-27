#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MOD = 998244353;
constexpr int MAX_N = 500000;

vector<i64> f(MAX_N+1, 1);
vector<i64> inv_f(MAX_N+1, 1);

i64 power(i64 x, i64 n) {
  i64 ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= MOD;
    }
    x = x * x;
    x %= MOD;
    n >>= 1;
  }
  return ans;
}

void precompute() {
  for (int i = 2; i <= MAX_N; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }
  inv_f[MAX_N] = power(f[MAX_N], MOD-2);
  for (int i = MAX_N-1; i >= 0; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }
}

i64 com(i64 n, i64 k) {
  if (n > MAX_N) {
    int p = max(n-k, k);
    int q = min(n-k, k);
    i64 ans = 1;
    for (i64 i = n; i > p; --i) {
      ans *= i;
      ans %= MOD;
    }
    for (i64 j = q; j >= 1; --j) {
      ans *= power(j, MOD-2);
      ans %= MOD;
    }
    return ans;
  } else {
    i64 ans = f[n] * inv_f[k];
    ans %= MOD;
    ans *= inv_f[n-k];
    ans %= MOD;
    return ans;
  }
}

void solve() {
  int n = 0, C = 0;
  cin >> n >> C;
  vector<int> left(n+1);
  vector<int> right(n+1);
  vector<int> vals(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> left[i] >> right[i] >> vals[i];
  }

  vector<int> ordering;
  function<void(int)> dfs = [&](int node) {
    if (node == -1) {
      return;
    }

    dfs(left[node]);
    ordering.push_back(vals[node]);
    dfs(right[node]);
  };

  dfs(1);

  ordering.insert(ordering.begin(), 1);
  ordering.push_back(C);

  i64 ans = 1;
  int L = 1;
  int last = 0;
  for (int i = 1; i < (int) ordering.size(); ++i) {
    if (ordering[i] != -1) {
      int R = ordering[i];
      int len = i-last-1;
      i64 result = com(R-L + len, len);
      // cout << "l=" << L << ",r=" << R << ", len=" << len << ", result=" << result << endl;
      L = ordering[i];
      last = i;
      ans *= result;
      ans %= MOD;
    }
  }
  cout << endl;

  cout << ans << endl;
}

int main() {
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