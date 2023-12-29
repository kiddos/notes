#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  i64 ans = 0;
  vector<bool> used(26);
  for (int i = 0; i < n; ++i) {
    int c = s[i] - 'a';
    if (used[c]) {
      continue;
    }

    used[c] = true;
    ans += n-i;
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
