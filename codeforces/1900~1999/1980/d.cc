#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> b(n+1);
  for (int i = 1; i < n; ++i) {
    b[i] = gcd(a[i-1], a[i]);
  }

  vector<bool> s(n+1, true), p(n+1, true);
  for (int i = 2; i < n; ++i) {
    p[i] = p[i-1] && (b[i] >= b[i-1]);
  }
  for (int i = n-2; i >= 0; --i) {
    s[i] = s[i+1] && (b[i+1] >= b[i]);
  }

  // for (int i = 0; i < n; ++i) cout << b[i] << " ";
  // cout << endl;

  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      if (s[i+2]) {
        cout << "YES" << endl;
        return;
      }
    } else if (i == n-1) {
      if (p[i-1]) {
        cout << "YES" << endl;
        return;
      }
    } else {
      int g = gcd(a[i-1], a[i+1]);
      if (i == 1) {
        if (s[i+2] && g <= b[i+2]) {
          cout << "YES" << endl;
          return;
        }
      } else if (i == n-2) {
        if (p[i-1] && g >= b[i-1]) {
          cout << "YES" << endl;
          return;
        }
      } else {
        if (s[i+2] && p[i-1] && g <= b[i+2] && g >= b[i-1]) {
          cout << "YES" << endl;
          return;
        }
      }
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
