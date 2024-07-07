#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  
  i64 ans = h[n-1];
  for (int i = n-2; i >= 0; --i) {
    if (h[i] <= h[i+1]) {
      h[i] = h[i+1] + 1;
    }
    ans = max(ans, h[i]);
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
