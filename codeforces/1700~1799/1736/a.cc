#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  int without_sort = 0;
  for (int i = 0; i < n; ++i) {
    without_sort += a[i] != b[i];
  }

  int with_sort = 1;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int i = 0; i < n; ++i) {
    with_sort += a[i] != b[i];
  }

  int ans = min(without_sort, with_sort);
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
