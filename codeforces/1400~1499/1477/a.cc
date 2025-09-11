#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;
  vector<i64> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  for (int i = 0; i < n; ++i) {
    if (x[i] == k) {
      cout << "YES" << endl;
      return;
    }
  }

  sort(x.begin(), x.end());
  // for (int i = 0; i < n; ++i) {
  //   i64 diff = abs(x[i] - k);
  //   for (int j = i+1; j < n; ++j) {
  //     i64 d = x[j] - x[i];
  //     if (diff % d == 0) {
  //       cout << "YES" << endl;
  //       return;
  //     }
  //   }
  // }
  // cout << "NO" << endl;
  i64 g = x[1] - x[0];
  for (int i = 2; i < n; ++i) {
    g = gcd(g, x[i] - x[0]);
  }

  for (int i = 0; i < n; ++i) {
    i64 diff = abs(x[i] - k);
    if (diff % g == 0) {
      cout << "YES" << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
