#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<int> h(n * 2);
  for (int i = 0; i < h.size(); ++i) cin >> h[i];

  sort(h.begin(), h.end());
  for (int i = 0; i < n; ++i) {
    if (h[i+n] - h[i] < x) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
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
