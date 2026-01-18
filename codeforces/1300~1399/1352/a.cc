#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s = to_string(n);
  int len = s.length();
  vector<string> ans;
  for (int i = 0; i < len; ++i) {
    string round(len - i, '0');
    if (s[i] == '0') {
      continue;
    }
    round[0] = s[i];
    ans.push_back(round);
  }
  cout << ans.size() << endl;
  for (string& si : ans) {
    cout << si << " ";
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
