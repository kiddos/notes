#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

string smallest(const string& s) {
  auto idx = s.find('1');
  if (idx == string::npos) {
    return s;
  }
  return s.substr(0, idx) + s.substr(idx+1);
}

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  string ans;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      string s2 = s.substr(0, i) + s.substr(i+1);
      string s3 = smallest(s2);
      if (ans.empty()) {
        ans = s3;
      } else {
        ans = max(ans, s3);
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
