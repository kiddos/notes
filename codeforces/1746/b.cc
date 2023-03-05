#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int total = accumulate(a.begin(), a.end(), 0);
  int l = 0, r = n-1;
  int ans = 0;
  while (l < r) {
    while (r >= 0 && a[r] == 1) {
      r--;
      total--;
    }
    while (l < n && a[l] == 0) {
      l++;
    }
    if (l < r) {
      a[l] = 0;
      a[r] = 1;
      total--;
      l++;
      r--;
      ans++;
    }
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
