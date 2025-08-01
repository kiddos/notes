#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> x(m);
  for (int i = 0; i < m; ++i) {
    cin >> x[i];
  }

  vector<i64> p = a;
  for (int i = 1; i < n; ++i) {
    p[i] += p[i-1];
  }
  map<i64,i64> prefixes;
  for (int i = n-1; i >= 0; --i) {
    prefixes[p[i]] = i;
  }
  for (auto it = next(prefixes.rbegin()); it != prefixes.rend(); ++it) {
    it->second = min(it->second, prev(it)->second);
  }

  i64 one_round = p.back();
  vector<i64> ans;
  for (int i = 0; i < m; ++i) {
    auto it = prefixes.lower_bound(x[i]);
    if (it != prefixes.end()) {
      ans.push_back(it->second);
    } else {
      if (one_round <= 0) {
        ans.push_back(-1);
      } else {
        i64 max_prefix = prefixes.rbegin()->first;
        i64 round_require = x[i] - max_prefix;
        i64 round = (round_require + one_round - 1) / one_round;
        i64 left = x[i] - round * one_round;
        it = prefixes.lower_bound(left);
        ans.push_back(it->second + round * n);
      }
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << " ";
  }
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
