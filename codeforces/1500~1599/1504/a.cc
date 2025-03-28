#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int insert = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] != 'a') {
      insert = n-i;
      break;
    }
  }
  if (insert >= 0) {
    s.insert(s.begin() + insert, 'a');
    cout << "YES" << endl;
    cout << s << endl;
  } else {
    cout << "NO" << endl;
  }
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
