#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  if (n <= 1) {
    cout << "0" << endl;
    return;
  }
  if (n < 10) {
    cout << n-1 << endl;
    return;
  }

  string s = to_string(n);
  string a, b;
  for (int i = 0; i < (int)s.length(); ++i) {
    if (i % 2 == 0) {
      a.push_back(s[i]);
    } else {
      b.push_back(s[i]);
    }
  }
  int x = stoi(a);
  int y = stoi(b);
  int ans = (x + 1) * (y + 1) - 2;
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
