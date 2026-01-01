#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  vector<string> parts;
  int n = s.length();
  string current;
  for (int i = 0; i <= n; ++i) {
    if (i == n || s[i] == '+') {
      parts.push_back(current);
      current.clear();
    } else {
      current.push_back(s[i]);
    }
  }
  sort(parts.begin(), parts.end());
  string ans;
  for (string p : parts) {
    if (ans.length()) {
      ans += "+";
    }
    ans += p;
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
