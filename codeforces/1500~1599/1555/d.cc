#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  string s;
  cin >> s;

  auto match_string = [&](const string &p) -> vector<int> {
    vector<int> diff(n);
    for (int i = 0; i < n; ++i) {
      if (s[i] != p[i % p.length()]) {
        diff[i]++;
      }
    }
    for (int i = 1; i < n; ++i) {
      diff[i] += diff[i-1];
    }
    return diff;
  };

  vector<string> possible = {"abc", "acb", "bac", "bca", "cab", "cba"};
  vector<vector<int>> p;
  for (string& pattern : possible) {
    p.push_back(match_string(pattern));
  }

  for (int i = 0; i < m; ++i) {
    int l = 0, r = 0;
    cin >> l >> r;
    r--;
    l--;
    int ans = numeric_limits<int>::max();
    for (int k = 0; k < 6; ++k) {
      ans = min(ans, p[k][r] - (l > 0 ? p[k][l-1] : 0));
    }
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
