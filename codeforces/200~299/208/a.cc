#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  string t = "WUB";
  string ans;
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    string sub = s.substr(i, 3);
    if (sub == t) {
      if (!ans.empty() && ans.back() != ' ') {
        ans.push_back(' ');
      }
      i += 2;
    } else {
      ans.push_back(s[i]);
    }
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
