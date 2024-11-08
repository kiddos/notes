#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> w(n), h(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> h[i];
  }
  int max_w = *max_element(w.begin(), w.end());
  int max_h = *max_element(h.begin(), h.end());
  int ans = max_w * 2 + max_h * 2;
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
