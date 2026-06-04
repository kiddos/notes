#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> target(n);
  iota(target.begin(), target.end(), 1);
  i64 prefix = 0;
  int mod = n+1;
  vector<array<i64,3>> ans;
  for (int i = n-1; i >= 0; --i) {
    i64 missing = target[i] - (a[i] + prefix);
    missing %= mod;
    missing += mod;
    missing %= mod;
    if (missing > 0) {
      ans.push_back({1, i+1, missing});
      prefix += missing;
    }
  }
  ans.push_back({2, n, mod});
  cout << ans.size() << endl;
  for (auto [type, i, x] : ans) {
    cout << type << " " << i << " " << x << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
