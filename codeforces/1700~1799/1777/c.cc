#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());

  vector<vector<int>> factors(n);
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    for (int d = 1; d*d <= x; ++d) {
      if (x % d == 0) {
        factors[i].push_back(d);
        factors[i].push_back(x / d);
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    vector<int>& f = factors[i];
    sort(f.begin(), f.end());
    f.erase(unique(f.begin(), f.end()), f.end());
  }

  constexpr int INF = numeric_limits<int>::max();
  int ans = INF;
  map<int, int> mods;
  for (int i = 0, j = 0; i < n; ++i) {
    for (int f : factors[i]) {
      if (f <= m) {
        mods[f]++;
      }
    }
    while (j < n && mods.size() == m) {
      ans = min(ans, a[i] - a[j]);
      for (int f : factors[j]) {
        if (f > m) continue;
        if (--mods[f] == 0) mods.erase(f);
      }
      j++;
    }
  }

  if (ans == INF) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
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
