#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  set<int> s;
  for (int i = 0; i <= n; ++i) {
    s.insert(i);
  }

  map<int, int> mexes;
  i64 total_mex = 0;
  for (int i = 0; i < n; ++i) {
    s.erase(a[i]);
    i64 mex = *s.begin();
    mexes[mex]++;
    total_mex += mex;
  }

  i64 current = total_mex;
  i64 ans = total_mex;
  for (int i = 0; i < n; ++i) {
    auto it = mexes.lower_bound(a[i]+1);
    while (it != mexes.end()) {
      mexes[a[i]] += it->second;
      current += (i64) a[i] * it->second;
      current -= (i64) it->first * it->second;

      mexes.erase(it);
      it = mexes.lower_bound(a[i]+1);
    }

    mexes[n]++;
    current += n;

    ans = max(ans, current);
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
