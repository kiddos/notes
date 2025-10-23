#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  // no change
  vector<i64> no_change(n);
  for (int i = 1; i < n; ++i) {
    no_change[i] = no_change[i-1] + abs(a[i] - a[i-1]);
  }
  // change i to previous or next value
  vector<i64> change(n);
  for (int i = 1; i < n; ++i) {
    change[i] = change[i-1] + abs(a[i-1] - a[i]);
    if (i >= 2) {
      change[i] = min(change[i], no_change[i-2] + abs(a[i-2] - a[i]));
    }
  }
  i64 ans = min(change[n-1], no_change[n-2]);
  i64 change_first = 0;
  for (int i = 2; i < n; ++i) {
    change_first += abs(a[i-1] - a[i]);
  }
  ans = min(ans, change_first);

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
