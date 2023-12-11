#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  vector<pair<char, int>> lower, upper;
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    char ch = s[i];
    if (isupper(ch)) {
      if (ch == 'B') {
        if (!upper.empty()) upper.pop_back();
      } else {
        upper.emplace_back(ch, i);
      }
    } else if (islower(ch)) {
      if (ch == 'b') {
        if (!lower.empty()) lower.pop_back();
      } else {
        lower.emplace_back(ch, i);
      }
    }
  }
  int i = 0, j = 0;
  string ans;
  while (i < (int)lower.size() || j < (int)upper.size()) {
    int i1 = i < (int)lower.size() ? lower[i].second : numeric_limits<int>::max();
    int i2 = j < (int)upper.size() ? upper[j].second : numeric_limits<int>::max();
    if (i1 < i2) {
      ans.push_back(lower[i].first);
      i++;
    } else {
      ans.push_back(upper[j].first);
      j++;
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
