#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  string ans;
  ans.push_back(s[0]);
  int n = s.length();
  for (int i = 1; i < n-1; i += 2) {
    ans.push_back(s[i]);
  }
  ans.push_back(s.back());
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
