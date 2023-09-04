#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int R = count(s.begin(), s.end(), '1');

  int ans = R;
  int n = s.length();
  int M = 0;
  int L = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    R -= s[i] == '1';
    M += s[i] == '0';

    while (j < i && L + R < M) {
      L += s[j] == '1';
      M -= s[j] == '0';
      j++;
    }
    // cout << "i=" << i << ", L=" << L << ", M=" << M << ", R=" << R << endl;
    int cost = max(L+R, M);
    ans = min(ans, cost);
  }

  cout << ans << endl;;
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
