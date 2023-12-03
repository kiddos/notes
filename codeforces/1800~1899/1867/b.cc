#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  int min_op = 0, correct = 0;
  int l = 0, r = n-1;
  while (l < r) {
    if (s[l] != s[r]) {
      min_op++;
    } else {
      correct++;
    }
    l++;
    r--;
  }

  string ans(n+1, '0');
  if (n % 2 == 1) {
    int max_change = min_op + correct * 2 + 1;
    for (int i = min_op; i <= max_change; ++i) ans[i] = '1';
  } else {
    int max_change = min_op + correct * 2;
    for (int i = min_op; i <= max_change; i += 2) ans[i] = '1';
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
