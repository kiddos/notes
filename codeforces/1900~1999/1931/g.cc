#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 1 -> 2
// 1 -> 3
// 2 -> 1
// 2 -> 4
// 3 -> 2
// 3 -> 3
// 4 -> 1
// 4 -> 4
//
// observation:
// only if 1 and 2 count have difference of at most 1
// then there will be an answer
// 3 can be insert after any 1
//   or before any 2
// 4 can be insert after any 2
//   or before any 1

constexpr int MOD = 998244353;
constexpr int MAX_N = 4000000;
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
  for (int i = MAX_N-1; i >= 1; --i) {
    inv_f[i] = inv_f[i+1] * (i+1);
    inv_f[i] %= MOD;
  }
}

i64 C(i64 n, i64 r) {
  i64 ans = f[n] * inv_f[r];
  ans %= MOD;
  ans *= inv_f[n-r];
  ans %= MOD;
  return ans;
}

void solve() {
  vector<int> c(4);
  for (int i = 0; i < 4; ++i) cin >> c[i];

  if (c[0] == 0 && c[1] == 0) {
    if (c[2] > 0 && c[3] > 0) {
      cout << "0" << endl;
    } else {
      cout << "1" << endl;
    }
  } else if (c[0] == c[1]) {
    // can start with c[0] or c[1]
    i64 ab = c[0];
    i64 ans = C(c[2] + ab, c[2]) * C(c[3] + ab - 1, c[3]);
    ans %= MOD;
    ans += C(c[2] + ab - 1, c[2]) * C(c[3] + ab, c[3]);
    ans %= MOD;
    cout << ans << endl;
  } else if (abs(c[0] - c[1]) == 1) {
    i64 ab = max(c[0], c[1]);
    // start with the one that is larger
    i64 ans = C(c[2] + ab - 1, c[2]) * C(c[3] + ab - 1, c[3]);
    ans %= MOD;
    cout << ans << endl;
  } else {
    cout << "0" << endl;
  }
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
