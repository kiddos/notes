#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  const string target = "2020";
  int t = target.length();
  for (int len = 0; len <= t; ++len) {
    string prefix = target.substr(0, len);
    string suffix = target.substr(len, t-len);
    if (s.substr(0, prefix.length()) == prefix && s.substr(n-suffix.length(), suffix.length()) == suffix) {
      cout << "YES" << endl;
      return;
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
