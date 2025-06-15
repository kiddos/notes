#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n), q(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> q[i];
  }

  constexpr int MOD = 998244353;
  vector<i64> p2(n, 1);
  for (int i = 1; i < n; ++i) {
    p2[i] = p2[i-1] * 2;
    p2[i] %= MOD;
  }

  vector<i64> r(n);
  int i1 = 0, i2 = 0;
  for (int i = 0; i < n; ++i) {
    if (p[i] > p[i1]) {
      i1 = i;
    }
    if (q[i] > q[i2]) {
      i2 = i;
    }

    if (p[i1] > q[i2]) {
      r[i] = p2[p[i1]] + p2[q[i-i1]];
    } else if (q[i2] > p[i1]) {
      r[i] = p2[q[i2]] + p2[p[i-i2]];
    } else {
      if (q[i-i1] >= p[i-i2]) {
        r[i] = p2[p[i1]] + p2[q[i-i1]];
      } else if (p[i-i2] > q[i-i1]) {
        r[i] = p2[q[i2]] + p2[p[i-i2]];
      }
    }
    r[i] %= MOD;
  }

  for (int i = 0; i < n; ++i) {
    cout << r[i] << " ";
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
