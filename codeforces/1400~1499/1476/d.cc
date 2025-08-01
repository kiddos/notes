#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  s = " " + s;

  vector<int> prefix(n+1, 1);
  for (int i = 1; i <= n; ++i) {
    if (s[i] != s[i-1] && s[i-1] != ' ') {
      prefix[i] = prefix[i-1]+1;
    }
  }
  vector<int> suffix(n+1, 1);
  for (int i = n-1; i >= 0; --i) {
    if (s[i] != s[i+1]) {
      suffix[i] += suffix[i+1];
    }
  }

  vector<int> ans(n+1);
  for (int i = 0; i <= n; ++i) {
    int total = 0;
    if (s[i] == 'L') {
      total += prefix[i];
    }
    if (i+1 <= n && s[i+1] == 'R') {
      total += suffix[i+1];
    }
    ans[i] = total + 1;
  }

  for (int i = 0; i <= n; ++i) {
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
