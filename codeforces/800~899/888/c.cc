#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  string s;
  cin >> s;
  vector<vector<int>> indices(26);
  int n = s.length();
  for (int i = 0; i < n; ++i) {
    indices[s[i]-'a'].push_back(i);
  }
  int ans = n;
  for (int c = 0; c < 26; ++c) {
    if (indices[c].empty()) {
      continue;
    }
    int last = -1;
    int max_dist = 0;
    for (int idx : indices[c]) {
      int dist = idx - last;
      max_dist = max(max_dist, dist);
      last = idx;
    }
    max_dist = max(max_dist, n - last);
    ans = min(ans, max_dist);
  }
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
