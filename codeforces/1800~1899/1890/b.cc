#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_ok(const string& s) {
  int n = s.length();
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i-1]) return false;
  }
  return true;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  if (is_ok(s)) {
    cout << "YES" << endl;
    return;
  }

  if (!is_ok(t)) {
    cout << "NO" << endl;
    return;
  }

  bool dup_one = false, dup_zero = false;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i-1]) {
      if (s[i] == '1') {
        dup_one = true;
      } else if (s[i] == '0') {
        dup_zero = true;
      }
    }
  }

  if (dup_one && !dup_zero) {
    if (t[0] == '0' && t.back() == '0') {
      cout << "YES" << endl;
      return;
    }
  }
  if (dup_zero && !dup_one) {
    if (t[0] == '1' && t.back() == '1') {
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
