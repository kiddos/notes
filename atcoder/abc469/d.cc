#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  vector<int> a(m), b(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i] >> b[i];
  }

  map<int,int> appear;
  map<pair<int,int>,int> pair_count;

  for (int i = 0; i < m; ++i) {
    appear[a[i]]++;
    appear[b[i]]++;
    pair_count[{a[i], b[i]}]++;
  }

  auto possible = [&](int x, int y) -> bool {
    pair<int,int> p = {min(x, y), max(x, y)};
    int total_covered = appear[x] + appear[y] - pair_count[p];
    return total_covered == m;
  };

  vector<pair<int,int>> c;
  for (int x = 1; x <= n; ++x) {
    int count = appear.count(x) ? appear[x] : 0;
    c.push_back({count, x});
  }
  sort(c.begin(), c.end());

  int ans = 0;
  for (int l = 0; l < n; ++l) {
    for (int r = n-1; r > l && c[l].first + c[r].first >= m; --r) {
      if (possible(c[l].second, c[r].second)) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
