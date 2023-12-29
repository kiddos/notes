#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> l(n);
  for (int i = 0; i < n; ++i) cin >> l[i];
  vector<int> r(n);
  for (int i = 0; i < n; ++i) cin >> r[i];
  vector<int> c(n);
  for (int i = 0; i < n; ++i) cin >> c[i];

  vector<pair<int,bool>> v;
  for (int i = 0; i < n; ++i) {
    v.emplace_back(l[i], false);
    v.emplace_back(r[i], true);
  }
  sort(v.begin(), v.end());

  vector<int> lens;
  int size = v.size();
  vector<int> s;
  for (int i = 0; i < size; ++i) {
    if (v[i].second) {
      lens.push_back(v[i].first - s.back());
      s.pop_back();
    } else {
      s.push_back(v[i].first);
    }
  }

  sort(lens.begin(), lens.end());
  sort(c.rbegin(), c.rend());
  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += (i64) c[i] * lens[i];
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
