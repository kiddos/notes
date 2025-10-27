#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  int i1 = 0;
  while (i1 < n) {
    if (s[i1] == '1') {
      int i2 = i1;
      while (i2 + 1 < n && s[i2 + 1] == '1') {
        i2++;
      }
      int len = i2 - i1 + 1;
      if (len >= k) {
        cout << "NO" << endl;
        return;
      }
      i1 = i2 + 1;
    } else {
      i1++;
    }
  }

  int x = n;
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      ans[i] = x--;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      ans[i] = x--;
    }
  }
  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
