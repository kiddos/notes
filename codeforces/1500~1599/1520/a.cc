#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  string s2;
  for (int i = 0; i < n; ++i) {
    if (s2.empty() || s[i] != s2.back()) {
      s2.push_back(s[i]);
    }
  }
  int m = s2.length();
  for (int i = 0; i < m; ++i) {
    for (int j = i+1; j < m; ++j) {
      if (s2[i] == s2[j]) {
        cout << "NO" << endl;
        return;
      }
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
