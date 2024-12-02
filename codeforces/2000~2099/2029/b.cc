#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s, r;
  cin >> s >> r;

  int one = 0, zero = 0;
  for (int i = 0; i < n; ++i) {
    one += s[i] == '1';
    zero += s[i] == '0';
  }

  for (char ch : r) {
    if (one == 0 || zero == 0) {
      cout << "NO" << endl;
      return;
    }

    one--;
    zero--;
    if (ch == '1') {
      one++;
    } else if (ch == '0') {
      zero++;
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
