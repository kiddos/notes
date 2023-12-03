#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_N = 200000;
constexpr int MOD = 998244353;

vector<i64> f(MAX_N+1, 1);

void precompute() {
  for (int i = 2; i <= MAX_N; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }
}

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int i = 0;
  int op = 0;
  i64 p = 1;
  int remove = 0;
  while (i < n) {
    int j = i;
    while (j < n && s[j] == s[i]) {
      j++;
    }
    int len = j-i;
    op += len - 1;
    if (len-1 > 0) {
      remove++;
    }
    p *= len;
    p %= MOD;
    i = j;
  }

  p *= f[op];
  p %= MOD;

  cout << op << " " << p << endl;
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
