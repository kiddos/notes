#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  vector<int> c(m);
  for (int i = 0; i < m; ++i) {
    cin >> c[i];
  }
  vector<pair<int,int>> m1, m2;
  for (int i = 0; i < m; ++i) {
    if (c[i] > 0) {
      m1.push_back({b[i], c[i]});
    } else {
      m2.push_back({b[i], c[i]});
    }
  }
  sort(m1.begin(), m1.end());
  sort(m2.begin(), m2.end());

  multiset<int> s(a.begin(), a.end());
  int ans = 0;
  for (auto [bi, ci] : m1) {
    auto it = s.lower_bound(bi);
    if (it == s.end()) {
      break;
    }
    int x = *it;
    s.erase(it);
    s.insert(max(x, ci));
    ans++;
  }
  for (auto [bi, ci] : m2) {
    auto it = s.lower_bound(bi);
    if (it == s.end()) {
      break;
    }
    s.erase(it);
    ans++;
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
