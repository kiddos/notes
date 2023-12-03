#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int k = 0;
  cin >> k;
  vector<char> c(k);
  for (int i = 0; i < k; ++i) cin >> c[i];

  unordered_set<char> chars(c.begin(), c.end());
  vector<int> next(n, -1);
  for (int i = n-1, last = -1; i >= 0; --i) {
    next[i] = last;
    if (chars.count(s[i])) {
      last = i;
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (next[i] >= 0) {
      ans = max(ans, next[i] - i);
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
