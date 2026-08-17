#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 000110000110000
// with some operation, we can move some 0 from 1 segment to answer
// but not all of 0s
// eg -> 011000000110000
//    -> 011011000000000
// by star bar theorem, the answer is C(n-1, k-1)
// and the result of 0s and 1s is independent

constexpr int MAX_N = 1e6;
constexpr int MOD = 998244353;
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
    x = (x * x) % MOD;
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
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  vector<pair<int,int>> segments;
  int idx = 0;
  while (idx < n) {
    int j = idx;
    while (j+1 < n && s[j+1] == s[j]) {
      j++;
    }
    int len = j-idx+1;
    segments.push_back({s[idx]-'0', len});
    idx = j+1;
  }

  vector<int> count(2), segment(2);
  for (auto [b, len] : segments) {
    count[b] += len;
    segment[b]++;
  }

  i64 ans = 1;
  if (count[0] > 0) {
    ans *= C(count[0]-1, segment[0] -1);
    ans %= MOD;
  }
  if (count[1] > 0) {
    ans *= C(count[1]-1, segment[1]-1);
    ans %= MOD;
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
