#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s, t;
  cin >> s >> t;
  vector<int> lower(26), upper(26);
  for (char ch : t) {
    if (islower(ch)) {
      lower[ch-'a']++;
    } else if (isupper(ch)) {
      upper[ch-'A']++;
    }
  }

  array<int,2> ans = {0, 0};
  int n = s.length();
  vector<bool> found(n);
  for (int i = 0; i < n; ++i) {
    if (islower(s[i])) {
      if (lower[s[i]-'a']) {
        lower[s[i]-'a']--;
        ans[0]++;
        found[i] = true;
      }
    } else if (isupper(s[i])) {
      if (upper[s[i]-'A']) {
        upper[s[i]-'A']--;
        ans[0]++;
        found[i] = true;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (found[i]) {
      continue;
    }
    if (islower(s[i])) {
      if (upper[s[i]-'a']) {
        upper[s[i]-'a']--;
        ans[1]++;
      }
    } else if (isupper(s[i])) {
      if (lower[s[i]-'A']) {
        lower[s[i]-'A']--;
        ans[1]++;
      }
    }
  }

  cout << ans[0] << " " << ans[1] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
