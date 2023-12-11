#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int z = 0, o = 0;
  bool diff = 0;
  for (int i = 0; i < n; ++i) {
    z += s[i] == '0';
    o += s[i] == '1';
    if (i+1 < n && s[i] != s[i+1]) {
      diff = true;
    }
  }

  if (z > o) {
    cout << "YES" << endl;
    return;
  }
  if (diff) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
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
