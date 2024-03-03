#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int ans = n-1;
  int i = 1;
  while (i < n && a[i] == a[i-1]) {
    i++;
  }
  ans = min(ans, n-i);
  int j = n-2;
  while (j >= 0 && a[j] == a[j+1]) {
    j--;
  }
  ans = min(ans, j+1);

  i = 0;
  j = n-1;
  while (i < n && a[i] == a[0]) {
    i++;
  }
  while (j >= 0 && a[j] == a[0]) {
    j--;
  }
  ans = min(ans, max(0, j-i+1));

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
