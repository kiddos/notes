#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool fill(i64 n, i64 m, vector<i64>& a) {
  if (n == 1) {
    // 1m
    for (i64 x : a) {
      if (x >= m) {
        return true;
      }
    }
    return false;
  } else if (n % 2 == 0) {
    // 2m, 2m, 2m... => need n/2 of 2m
    i64 total = 0;
    for (i64 x : a) {
      if (x >= 2 * m) {
        total += x / m;
      }
    }
    return total >= n;
  } else {
    // 2m, 2m, ... 3m
    // => need a 3m and
    // (n-3) / 2  2m
    bool has_3 = false;
    i64 total = 0;
    for (int x : a) {
      if (x >= 3 * m && !has_3) {
        has_3 = true;
      }
      if (x >= 2 * m) {
        total += x / m;
      }
    }
    return total >= n && has_3;
  }
}

void solve() {
  i64 n = 0, m = 0;
  int k = 0;
  cin >> n >> m >> k;
  vector<i64> a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i];
  }

  bool ans = fill(n, m, a) || fill(m, n, a);
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
