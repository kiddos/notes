#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  int l = 0;
  vector<bool> fixed(n);
  while (l < n) {
    if (s[l] == '0') {
      int r = l;
      while (r+1 <  n && s[r+1] == '0') {
        r++;
      }
      int len = r-l+1;
      if (len >= 2 || l == 0 || r == n-1) {
        for (int k = l; k <= r; ++k) {
          fixed[k] = true;
        }
      }
      l = r +1;
    } else {
      l++;
    }
  }
  // for (int i = 0; i < n; ++i) {
  //   cout << fixed[i] << " ";
  // }
  // cout << endl;

  for (int i = 0; i < n; ++i) {
    if (s[i] == '0' && !fixed[i]) {
      if (i >= 2 && fixed[i-2]) {
        fixed[i] = true;
      }
    }
  }
  for (int i = n-1; i >= 0; --i) {
    if (s[i] == '0' && !fixed[i]) {
      if (i+2 < n && fixed[i+2]) {
        fixed[i] = true;
      }
    }
  }
  // for (int i = 0; i < n; ++i) {
  //   cout << fixed[i] << " ";
  // }
  // cout << endl;

  l = 0;
  while (l < n) {
    if (s[l] == '0' && !fixed[l]) {
      int r = l;
      int count = 1;
      if (r+2 < n && s[r+2] == '0') {
        count++;
        r += 2;
      }
      if (count % 2 == 0) {
        for (int k = l; k <= r; k += 2) {
          fixed[k] = true;
        }
      }
      l = r+1;
    } else {
      l++;
    }
  }

  // for (int i = 0; i < n; ++i) {
  //   cout << fixed[i] << " ";
  // }
  // cout << endl;

  for (int i = 0; i < n; ++i) {
    if (s[i] == '0' && !fixed[i]) {
      cout << "NO" << endl;
      return;
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
