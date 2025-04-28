#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int l = 1, r = n;
  vector<int> ans;
  int len = s.length();
  for (int i = len-1; i >= 0; --i) {
    if (s[i] == '<') {
      ans.push_back(l++);
    } else if (s[i] == '>') {
      ans.push_back(r--);
    }
  }
  ans.push_back(l++);
  reverse(ans.begin(), ans.end());
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
