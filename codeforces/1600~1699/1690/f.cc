#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  s = " " + s;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) cin >> p[i];

  vector<bool> visited(n+1);
  function<void(int,string&)> dfs = [&](int i, string& segment) {
    if (visited[i]) return;
    visited[i] = true;
    segment.push_back(s[i]);
    dfs(p[i], segment);
  };

  auto find_first_cycle = [&](const string& segment) -> int {
    for (int i = 0; i < segment.length(); ++i) {
      string s2 = segment.substr(i+1) + segment.substr(0, i+1);
      if (s2 == segment) {
        return i+1;
      }
    }
    return segment.length();
  };

  vector<int> rotate;
  for (int i = 1; i <= n; ++i) {
    if (visited[i]) continue;
    string segment;
    dfs(i, segment);

    int p = find_first_cycle(segment);
    rotate.push_back(p);
  }

  i64 ans = rotate[0];
  for (int i = 1; i < rotate.size(); ++i) {
    ans = ans * rotate[i] / (gcd(ans, rotate[i]));
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
