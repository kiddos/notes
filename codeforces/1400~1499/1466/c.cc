#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  int n = s.length();
  int ans = 0;
  for (int i = 1; i < n; ++i) {
    string found;
    for (int j = i-2; j < i; ++j) {
      if (j >= 0 && j < n && j != i) {
        found.push_back(s[j]);
      }
    }
    if (found.find(s[i]) == string::npos) {
      continue;
    }

    for (char c = 'a'; c <= 'z'; ++c) {
      bool not_found = found.find(c) == string::npos;
      if (i+2 < n) {
        if (not_found && c != s[i+1] && c != s[i+2]) {
          s[i] = c;
          ans++;
          break;
        }
      } else if (i+1 < n) {
        if (not_found && c != s[i+1]) {
          s[i] = c;
          ans++;
          break;
        }
      } else {
        if (not_found) {
          s[i] = c;
          ans++;
          break;
        }
      }
    }
  }
  // cout << s << endl;

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
