#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }
  vector<int> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
  }
  int q = 0;
  cin >> q;
  vector<i64> a(q);
  for (int i = 0 ; i < q; ++i) {
    cin >> a[i];
  }

  auto query = [&](i64 x) -> bool {
    // cout << "x=" << x << endl;
    auto it = lower_bound(p.begin(), p.end(), x);
    if (it == p.end()) {
      return true;
    }

    i64 t = 0;
    i64 position = x;
    int idx = it - p.begin();
    int direction = 1;
    int moves = 0;
    while (moves++ <= n * k && idx >= 0 && idx < n) {
      // cout << "idx=" << idx << endl;
      i64 time_required = abs(p[idx] - position);
      t += time_required;
      position = p[idx];
      if (t % k == d[idx]) {
        // red light
        direction = -direction;
      }
      idx += direction;
    }
    return idx < 0 || idx >= n;
  };

  for (int i = 0; i < q; ++i) {
    bool result = query(a[i]);
    if (result) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
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
