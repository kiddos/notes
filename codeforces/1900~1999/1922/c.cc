#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> closest(n);
  closest[0] = 1;
  closest[n-1] = n-2;
  for (int i = 1; i < n-1; ++i) {
    int d1 = a[i] - a[i-1];
    int d2 = a[i+1] - a[i];
    if (d1 < d2) {
      closest[i] = i-1;
    } else {
      closest[i] = i+1;
    }
  }

  vector<int> go_right(n);
  for (int i = 1; i < n; ++i) {
    if (closest[i-1] == i) {
      go_right[i] = 1;
    } else {
      go_right[i] = a[i] - a[i-1];
    }
    go_right[i] += go_right[i-1];
  }
  vector<int> go_left(n);
  for (int i = n-2; i >= 0; --i) {
    if (closest[i+1] == i) {
      go_left[i] = 1;
    } else {
      go_left[i] = a[i+1] - a[i];
    }
    go_left[i] += go_left[i+1];
  }

  int q = 0;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int x = 0, y = 0;
    cin >> x >> y;
    x--;
    y--;
    if (x < y) {
      int ans = go_right[y] - go_right[x];
      cout << ans << endl;
    } else {
      int ans = go_left[y] - go_left[x];
      cout << ans << endl;
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
