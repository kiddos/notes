#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  if (s[0] == '1' || s.back() == '1') {
    cout << "YES" << endl;
    return;
  }

  int one = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      one++;
    } else {
      one = 0;
    }
    if (one >= 2) {
      cout << "YES" << endl;
      return;
    }
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
