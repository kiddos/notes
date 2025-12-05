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

  vector<int> right(n), left(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '*' || s[i] == '>') {
      right[i]++;
    }
    if (s[i] == '*' || s[i] == '<') {
      left[i]++;
    }
  }
  for (int i = 1; i < n; ++i) {
    right[i] += right[i-1];
  }
  for (int i = n-2; i >= 0; --i) {
    left[i] += left[i+1];
  }

  for (int i = 0; i < n; ++i) {
    if (s[i] == '*') {
      if ((i+1 < n && left[i+1]) || (i > 0 && right[i-1])) {
        cout << "-1" << endl;
        return;
      }
    } else if (s[i] == '>') {
      if (i+1 < n && left[i+1]) {
        cout << "-1" << endl;
        return;
      }
    } else if (s[i] == '<') {
      if (i > 0 && right[i-1]) {
        cout << "-1" << endl;
        return;
      }
    }
  }
  int ans = max(left[0], right[n-1]);
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
