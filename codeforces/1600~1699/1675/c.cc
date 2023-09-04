#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();

  if (n == 1) {
    cout << "1" << endl;
    return;
  }

  if (s == string(n, '?')) {
    cout << n << endl;
    return;
  }

  int one = count(s.begin(), s.end(), '1');
  int zero = count(s.begin(), s.end(), '0');
  if (one == 0) {
    for (int i = 0; i < n; ++i) if (s[i] == '0') {
      cout << i+1 << endl;
      return;
    }
  } else if (zero == 0) {
    for (int i = n-1; i >= 0; --i) if (s[i] == '1') {
      cout << n-i << endl;
      return;
    }
  }

  int left = -1, right = -1;
  bool found_zero = false;
  for (int i = 0; i < n; ++i) {
    one -= s[i] == '1';
    zero -= s[i] == '0';

    if (s[i] == '0') {
      if (!found_zero) {
        found_zero = true;

        // lying
        if (left < 0) left = i;
        right = i;
      }
    } else if (s[i] == '1') {
      if (one == 0) {
        // lying
        if (left < 0) left = i;
        right = i;
      }
    }
  }

  cout << right - left + 1 << endl;
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
