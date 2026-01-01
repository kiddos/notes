#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  // -----<<<---
  // ----><<<---
  bool has_left = false, has_right = false;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '<') {
      has_left = true;
    }
    if (s[i] == '>') {
      has_right = true;
    }
  }

  if (!has_left || !has_right) {
    cout << n << endl;
    return;
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '-' || s[(i+1)%n] == '-') {
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
