#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0, k = 0, H = 0;
  cin >> n >> m >> k >> H;

  vector<int> h(n);
  for (int i = 0; i < n; ++i) cin >> h[i];

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int diff = abs(H - h[i]);
    if (diff % k == 0 && diff / k <= m-1 && diff > 0) {
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
