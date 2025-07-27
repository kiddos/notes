#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int i = 0;
  int ans = 0;
  while (i < n) {
    if (a[i] == 0) {
      int j = i;
      while (j+1 < n && a[j+1] == 0 && j+1-i+1 <= k) {
        j++;
      }
      if (j-i+1 == k) {
        ans++;
        i = j + 2;
      } else {
        i = j+1;
      }
    } else {
      i++;
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
