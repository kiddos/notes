#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  vector<int> zeros_before(n);
  for (int i = 0, z = 0; i < n; ++i) {
    zeros_before[i] = z;
    if (s[i] == '0') {
      z++;
    } else {
      z = 0;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x = 0;
    if (s[i] == '1') {
      for (int j = 0; j < 20 && i+j < n; ++j) {
        int b = s[i+j]-'0';
        x = (x<< 1) | b;
        int require_zeros = x - (j+1);
        if (require_zeros <= zeros_before[i]) {
          ans++;
        }
      }
    }
  }
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
