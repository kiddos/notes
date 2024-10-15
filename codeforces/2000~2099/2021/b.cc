#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  map<int, vector<int>> g;
  for (int i = 0; i < n; ++i) {
    g[a[i] % x].push_back(a[i]);
  }
  for (auto& [x, list] : g) {
    sort(list.rbegin(), list.rend());
  }

  for (int i = 0; i < n; ++i) {
    if (g[i % x].empty() || g[i % x].back() > i) {
      cout << i << endl;
      return;
    } else {
      g[i % x].pop_back();
    }
  }
  cout << n << endl;
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
