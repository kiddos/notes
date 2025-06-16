#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n+2);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  vector<i64> left(n+2), right(n+2), start(n+2);
  for (int i = 1; i <= n; ++i) {
    int x = a[i], y = a[i], z = a[i];
    while (x % 2 == 0 && x / 2 != a[i-1]) {
      x /= 2;
    }
    while (y % 2 == 0 && y / 2 != a[i+1]) {
      y /= 2;
    }
    while (z % 2 == 0) {
      z /= 2;
    }

    left[i] = (a[i] - x) / z + 1;
    right[i] = (a[i] - y) / z + 1;
    start[i] = a[i] / z;
  }

  vector<i64> prefix = right;
  for (int i = 1; i <= n; ++i) {
    prefix[i] += prefix[i-1];
  }
  vector<i64> suffix = left;
  for (int i = n; i >= 1; --i) {
    suffix[i] += suffix[i+1];
  }

  for (int i = 1; i <= n; ++i) {
    i64 total = start[i] + prefix[i-1] + suffix[i+1];
    // cout << "total=" << total << endl;
    if (total >= k) {
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
