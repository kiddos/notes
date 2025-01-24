#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  i64 x = 0;
  cin >> n >> k >> x;
  string s;
  cin >> s;

  x--;

  vector<pair<char,i64>> g;
  int i = 0;
  while (i < n) {
    if (s[i] == 'a') {
      g.emplace_back(s[i], 1);
      i++;
    } else if (s[i] == '*') {
      int len = 1;
      int j = i;
      while (j+1 < n && s[j+1] == '*') {
        len++;
        j++;
      }
      i = j+1;
      g.emplace_back('b', len*k+1);
    }
  }

  int size = g.size();
  string ans;
  for (int i = size-1; i >= 0; --i) {
    if (g[i].first == 'a') {
      ans.push_back('a');
    } else {
      ans += string(x % g[i].second, 'b');
      x /= g[i].second;
    }
  }
  reverse(ans.begin(), ans.end());
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
