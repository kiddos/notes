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
  sort(a.begin(), a.end());
  int ans = n;
  for (int i = 0; i < n; ++i) {
    if ((a.back() + a[i]) % 2 == 0) {
      ans = min(ans, i);
    }
  }
  for (int i = n-1; i >= 0; --i) {
    if ((a[0] + a[i]) % 2 == 0) {
      ans = min(ans, n-i-1);
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
