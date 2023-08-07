#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  i64 sum = accumulate(a.begin(), a.end(), 0LL);
  if (sum != 0) {
    cout << "NO" << endl;
    return;
  }

  // b[i] means number of 1 ops
  // c[i] means number of 2 ops
  // a[i] = b[i] - c[i]
  // c[i] = b[i-1]
  // => a[i] = b[i] - b[i-1]
  // => b[i] = a[i] + b[i-1]
  vector<i64> b(n);
  b[0] = a[0];
  for (int i = 1; i < n; ++i) {
    b[i] = b[i-1] + a[i];
  }

  bool should_be_zero = false;
  for (int i = 0; i < n; ++i) {
    if (b[i] < 0) {
      cout << "NO" << endl;
      return;
    }
    if (b[i] == 0) {
      should_be_zero = true;
    }
    if (should_be_zero && b[i] > 0) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
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
