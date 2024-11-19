#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s, t;
  cin >> s >> t;
  vector<vector<int>> indices(26);

  for (int i = 0; i < (int)s.length(); ++i) {
    int c = s[i] - 'a';
    indices[c].push_back(i);
  }

  for (int i = 0; i < (int)t.length(); ++i) {
    int c = t[i] - 'a';
    string prefix = t.substr(0, i);
    string suffix = t.substr(i+1);
    reverse(suffix.begin(), suffix.end());

    int require_size = max(prefix.length(), suffix.length());
    for (int j : indices[c]) {
      if (j < require_size) continue;
      string s1 = s.substr(j-prefix.length(), prefix.length());
      string s2 = s.substr(j-suffix.length(), suffix.length());
      if (s1 == prefix && s2 == suffix) {
        cout << "YES" << endl;
        return;
      }
    }
  }
  cout << "NO" << endl;
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
