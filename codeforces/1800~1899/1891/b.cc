#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> x(q);
  for (int i = 0; i < q; ++i) cin >> x[i];

  map<int, vector<int>> b;
  for (int i = 0; i < n; ++i) {
    int x = (a[i] & (-a[i]));
    b[x].push_back(i);
  }
  for (int i = 0; i < q; ++i) {
    auto it = b.lower_bound(1<<x[i]);
    for (; it != b.end(); ++it) {
      for (int idx : it->second) {
        a[idx] += 1 << (x[i]-1);
        b[1 << (x[i]-1)].push_back(idx);
      }
      it->second.clear();
    }
  }

  for (int i = 0; i < n; ++i) cout << a[i] << " ";
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
