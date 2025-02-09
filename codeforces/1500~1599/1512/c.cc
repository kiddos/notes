#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0;
  cin >> a >> b;
  string s;
  cin >> s;
  int n = s.length();
  int l = 0, r = n-1;
  while (l < r) {
    if (s[l] != s[r]) {
      if (s[l] == '?') {
        s[l] = s[r];
      } else if (s[r] == '?') {
        s[r] = s[l];
      } else {
        cout << "-1" << endl;
        return;
      }
    }
    l++;
    r--;
  }

  l = 0, r = n-1;
  bool single = false;
  while (l <= r) {
    if (l == r) {
      if (s[l] == '0') {
        a--;
      } else if (s[l] == '1') {
        b--;
      } else if (s[l] == '?') {
        single = true;
      }
    } else {
      if (s[l] == '0') {
        a -= 2;
      } else if (s[l] == '1') {
        b -= 2;
      }
    }

    l++;
    r--;
  }

  if (a < 0 || b < 0) {
    cout << "-1" << endl;
    return;
  }

  if (a % 2 == 1 && b % 2 == 1) {
    cout << "-1" << endl;
    return;
  }
  
  if ((a % 2 == 1 || b % 2 == 1) && !single) {
    cout << "-1" << endl;
    return;
  }

  l = 0, r = n-1;
  while (l <= r) {
    if (l == r) {
      if (s[l] == '?') {
        if (a) {
          s[l] = '0';
        } else if (b) {
          s[l] = '1';
        }
      }
    } else {
      if (s[l] == '?') {
        if (a >= 2) {
          s[l] = s[r] = '0';
          a -= 2;
        } else if (b >= 2) {
          s[l] = s[r] = '1';
          b -= 2;
        }
      }
    }

    l++;
    r--;
  }

  cout << s << endl;
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
