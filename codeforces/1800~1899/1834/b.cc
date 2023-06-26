#include <bits/stdc++.h>

using namespace std;

void solve() {
  string L, R;
  cin >> L >> R;
  if (L.length() < R.length()) {
    L = string(R.length() - L.length(), '0') + L;
  }

  int n = R.length();
  int ans = 0;
  bool diff = false;
  for (int i = 0; i < n; ++i) {
    if (diff) {
      ans += 9;
    } else if (R[i] != L[i]) {
      ans += abs(R[i] - L[i]);
      diff = true;
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
