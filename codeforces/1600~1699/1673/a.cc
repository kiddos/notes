#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  if (n == 1) {
    cout << "Bob " << s[0] - 'a' + 1 << endl;
    return;
  } else if (n % 2 == 0) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += s[i] - 'a' + 1;
    }
    cout << "Alice " << ans << endl;
  } else {
    int total = 0;
    for (int i = 0; i < n; ++i) {
      total += s[i] - 'a' + 1;
    }
    int prefix = total - (s.back() - 'a' + 1);
    int suffix = total - (s[0] - 'a' + 1);
    int alice = max(prefix, suffix);
    int bob = total - alice;
    cout << "Alice " << alice - bob << endl;
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
