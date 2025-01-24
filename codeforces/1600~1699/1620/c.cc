#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using u64 = unsigned long long;

void solve() {
  int n = 0, k = 0;
  u64 x = 0;
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
  u64 total = 1;
  for (int i = size-1; i >= 0; --i) {
    if ((double)total * g[i].second > x) {
      for (int j = i-1; j >= 0; --j) {
        if (g[j].first == 'b') {
          g[j].second = 1;
        }
      }
      u64 p = (total + x -1) / x;
      total *= (p+1);
      g[i].second = p+1;
      break;
    } else {
      total *= g[i].second;
    }
  }

  string ans;
  for (auto& [c, p] : g) {
    total /= p;
    if (c == 'b') {
      if (p > 1 && total > 0) {
        u64 take = x / total;
        x -= take * total;
        if (take > 0) {
          ans += string(take, 'b');
        }
      }
    } else {
      ans.push_back('a');
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
