#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int idx = 0;
  int max_len = 0;
  while (idx < n) {
    if (s[idx] == '*') {
      idx++;
    } else {
      int j = idx;
      while (j+1 < n && s[j+1] == s[j]) {
        j++;
      }
      max_len = max(max_len, j-idx+1);
      idx = j+1;
    }
  }

  int ans = (max_len+1) / 2;
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
