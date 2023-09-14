#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, a = 0, q = 0;
  cin >> n >> a >> q;
  string s;
  cin >> s;

  int always = a;
  if (always == n) {
    cout << "YES" << endl;
    return;
  }

  for (char ch : s) {
    if (ch == '+') {
      always++;
    } else if (ch == '-') {
      always--;
    }
    if (always == n) {
      cout << "YES" << endl;
      return;
    }
  }

  int online = count(s.begin(), s.end(), '+');
  if (a + online >= n) {
    cout << "MAYBE" << endl;
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
