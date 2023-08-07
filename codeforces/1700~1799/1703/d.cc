#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> S(n);
  for (int i = 0; i < n; ++i) cin >> S[i];

  unordered_set<string> found(S.begin(), S.end());
  string ans(n, '0');
  for (int i = 0; i < n; ++i) {
    int len = S[i].length();
    for (int l = 1; l <= len-1; ++l) {
      string pre = S[i].substr(0, l);
      string suf = S[i].substr(l);
      if (found.count(pre) && found.count(suf)) {
        ans[i] = '1';
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
