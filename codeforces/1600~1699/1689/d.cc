#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// I need 4 points here to work (not 2 points)
//
// so if this type of question appear again, need to think about the 4 quadrant
// so the top-left corner should have the min(i+j),
// the top-right corner should have the min(i-j)
// the bot-left corner should have the max(i-j)
// the bot-right corner should have the max(i+j)
//
// find these 4 points that is black and scan the grid again

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> matrix(n);
  for (int i = 0; i < n; ++i) cin >> matrix[i];

  pair<int,int> a = {-1, -1}, b = {-1, -1}, c = {-1, -1}, d = {-1, -1};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) if (matrix[i][j] == 'B') {
      if (a.first == -1 || i-j < a.first - a.second) a = {i, j};
      if (b.first == -1 || i+j < b.first + b.second) b = {i, j};
      if (c.first == -1 || i-j > c.first - c.second) c = {i, j};
      if (d.first == -1 || i+j > d.first + d.second) d = {i, j};
    }
  }

  int best = numeric_limits<int>::max();
  pair<int,int> ans;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int dist = max({
        abs(i - a.first) + abs(j - a.second),
        abs(i - b.first) + abs(j - b.second),
        abs(i - c.first) + abs(j - c.second),
        abs(i - d.first) + abs(j - d.second),
      });
      if (dist < best) {
        best = dist;
        ans = {i, j};
      }
    }
  }

  cout << ans.first+1 << " " << ans.second+1 << endl;
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
