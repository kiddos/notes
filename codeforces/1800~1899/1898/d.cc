#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  i64 base = 0;
  for (int i = 0; i < n; ++i) {
    base += abs(a[i] - b[i]);
  }

  vector<array<int,3>> p;
  for (int i = 0; i  < n; ++i) {
    int x1 = min(a[i], b[i]);
    int x2 = max(a[i], b[i]);
    p.push_back({x1, x2, i});
  }
  sort(p.begin(), p.end());

  i64 ans = base;
  priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
  for (int k = 0; k < n; ++k) {
    int i = p[k][2];
    if (!pq.empty()) {
      auto [x2, x1, j] = pq.top();
      if (x2 < p[k][0]) {
        i64 ans2 = base - (abs(a[j] - b[j]) + abs(a[i] - b[i])) +
          (abs(a[j] - b[i]) + abs(b[j] - a[i]));
        ans = max(ans, ans2);
      }
    }
    pq.push({p[k][1], p[k][0], i});
  }

  cout << ans << endl;
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
