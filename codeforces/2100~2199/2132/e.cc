#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, q = 0;
  cin >> n >> m >> q;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  sort(a.rbegin(), a.rend());
  sort(b.rbegin(), b.rend());

  vector<i64> pa = {0};
  for (int i = 0; i < n; ++i) {
    pa.push_back(pa.back() + a[i]);
  }
  vector<i64> pb = {0};
  for (int i = 0; i < m; ++i) {
    pb.push_back(pb.back() + b[i]);
  }

  int size = m + n;
  vector<array<i64,3>> greedy_path = {{0, 0, 0}};
  i64 greedy = 0;
  for (int k = 0, i = 0, j = 0; k < size; ++k) {
    if (i == n) {
      greedy += b[j++];
    } else if (j == m) {
      greedy += a[i++];
    } else {
      if (a[i] > b[j]) {
        greedy += a[i++];
      } else {
        greedy += b[j++];
      }
    }
    greedy_path.push_back({greedy, i, j});
  }

  vector<i64> ans(q);
  for (int i = 0; i < q; ++i) {
    int x = 0, y = 0, z = 0;
    cin >> x >> y >> z;
    auto [g, take_a, take_b] = greedy_path[z];
    if (take_a <= x && take_b <= y) {
      ans[i] = g;
    } else if (take_a > x) {
      int swap_size = take_a - x;
      ans[i] = g - (pa[take_a] - pa[take_a - swap_size]) + (pb[take_b + swap_size] - pb[take_b]);
    } else if (take_b > y) {
      int swap_size = take_b - y;
      ans[i] = g - (pb[take_b] - pb[take_b - swap_size]) + (pa[take_a + swap_size] - pa[take_a]);
    }
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << endl;
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
