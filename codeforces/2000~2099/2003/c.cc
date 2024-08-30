#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n  = 0;
  cin >> n;
  string s;
  cin >> s;
  vector<int> count(26);
  for (int i = 0; i < n; ++i) {
    count[s[i]-'a']++;
  }
  vector<pair<int,char>> p;
  for (int i = 0; i < 26; ++i) {
    p.emplace_back(count[i], i + 'a');
  }
  sort(p.rbegin(), p.rend());
  while (!p.empty() && p.back().first == 0) {
    p.pop_back();
  }

  string ans = s;
  int i = 0;
  for (auto& [c, ch] : p) {
    while (c-- > 0) {
      ans[i] = ch;
      i += 2;
      if (i >= n) {
        i = 1;
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
