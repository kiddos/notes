#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0, x = 0;
  cin >> n >> k >> x;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<i64> require;
  for (int i = 1; i < n; ++i) {
    i64 diff = a[i] - a[i-1];
    if (diff > x) {
      i64 count = (diff + x - 1) / x - 1;
      require.push_back(count);
    } 
  }
  sort(require.begin(), require.end());
  int ans = require.size() + 1;
  for (int i = 0; i < (int)require.size() && k > 0; ++i) {
    if (k >= require[i]) {
      ans--;
      k -= require[i];
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
