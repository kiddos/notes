#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<string> a(2);
  cin >> a[0];
  cin >> a[1];

  string ans;
  queue<pair<int,int>> q;
  q.push({0, 0});
  vector<vector<bool>> visited(2, vector<bool>(n));
  visited[0][0] = true;
  while (!q.empty()) {
    string chars;
    vector<pair<int,int>> pos;
    for (int size = q.size(); size > 0; --size) {
      auto [r, c] = q.front();
      q.pop();
      chars.push_back(a[r][c]);
      pos.push_back({r, c});
    }

    char min_char = *min_element(chars.begin(), chars.end());
    ans.push_back(min_char);
    for (int i = 0; i < (int)chars.size(); ++i) {
      if (chars[i] != min_char) {
        continue;
      }

      auto [r, c] = pos[i];
      if (r+1 < 2 && !visited[r+1][c]) {
        q.push({r+1, c});
        visited[r+1][c] = true;
      }
      if (c+1 < n && !visited[r][c+1]) {
        q.push({r, c+1});
        visited[r][c+1] = true;
      }
    }
  }

  vector<vector<i64>> memo(2, vector<i64>(n, -1));
  function<i64(int,int)> dp = [&](int r, int c) -> i64 {
    if (r >= 2 || c >= n) return 0;
    if (r == 1 && c == n-1) return 1;
    if (a[r][c] != ans[c+r]) return 0;
    if (memo[r][c] >= 0) return memo[r][c];
    return memo[r][c] = dp(r+1, c) + dp(r, c+1);
  };

  i64 count = dp(0, 0);
  cout << ans << endl;
  cout << count << endl;
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
