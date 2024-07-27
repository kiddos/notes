#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  string t;
  cin >> t;

  if (s == t) {
    cout << "YES" << endl;
    return;
  }

  int k = 0;
  while (k < n && s[k] == '0') k++;
  for (int i = 0; i < k; ++i) {
    if (s[i] != t[i]) {
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
