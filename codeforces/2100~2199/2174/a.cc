#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s, t;
  cin >> s >> t;
  vector<int> available(26);
  for (char ch : t) {
    int c = ch - 'a';
    available[c]++;
  }

  for (char ch : s) {
    int c = ch - 'a';
    if (available[c] == 0) {
      cout << "Impossible" << endl;
      return;
    }
    available[c]--;
  }

  string ans;
  int c = 0;
  for (int j = 0; j < (int)s.length(); ++j) {
    while (c < 26 && c + 'a' < s[j]) {
      ans += string(available[c], c + 'a');
      c++;
    }
    ans.push_back(s[j]);
  }
  while (c < 26) {
    ans += string(available[c], c + 'a');
    c++;
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
