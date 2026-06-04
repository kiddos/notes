#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_valid(const string& s, int l, int r, string& replace) {
  int n = s.length();
  vector<bool> condition(3);
  for (int i = 0; i < n; ++i) {
    if (i >= l && i <= r) {
      continue;
    }
    if (isupper(s[i])) {
      condition[0] = true;
    } else if (islower(s[i])) {
      condition[1] = true;
    } else if (isdigit(s[i])) {
      condition[2] = true;
    }
  }
  int ignore_len = r-l+1;
  int missing = 0;
  replace.clear();
  string replacement = "Aa0";
  for (int i = 0; i < 3; ++i) {
    if (!condition[i]) {
      missing++;
      replace.push_back(replacement[i]);
    }
  }
  return missing <= ignore_len;
}

void solve() {
  string s;
  cin >> s;
  string mid;
  if (is_valid(s, -1, -2, mid)) {
    cout << s << endl;
    return;
  }

  int n = s.length();
  for (int len = 1; len <= 3; ++len) {
    for (int l = 0; l <= n-len; ++l) {
      int r = l + len-1;
      if (is_valid(s, l, r, mid)) {
        string prefix = s.substr(0, l);
        string suffix = s.substr(r+1);
        string ans = prefix + mid + suffix;
        cout << ans << endl;
        return;
      }
    }
  }
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
