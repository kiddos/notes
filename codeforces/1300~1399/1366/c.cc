#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a[i][j];
    }
  }

  int total = n-1 + m-1;
  int max_step = (total - 1) / 2;
  queue<pair<int,int>> q;
  q.push({0, 0});
  q.push({n-1, m-1});
  vector<vector<bool>> visited(n, vector<bool>(m));
  visited[0][0] = true;
  visited[n-1][m-1] = true;

  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  int step = 0;
  vector<vector<int>> dists(max_step+1);
  while (!q.empty() && step <= max_step) {
    for (int size = q.size(); size > 0; --size) {
      auto [r, c] = q.front();
      q.pop();

      dists[step].push_back(a[r][c]);
      
      for (vector<int>& d : delta) {
        int r2 = r + d[0], c2 = c + d[1];
        if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) continue;
        if (visited[r2][c2]) continue;
        visited[r2][c2] = true;
        q.push({r2, c2});
      }
    }
    step++;
  }

  // for (int d = 0; d <= max_step; ++d) {
  //   cout << "d=" << d << endl;
  //   for (int x : dists[d]) {
  //     cout << x << " ";
  //   }
  //   cout << endl;
  // }

  int ans = 0;
  for (int d = 0; d <= max_step; ++d) {
    int total_count = dists[d].size();
    int total_ones = accumulate(dists[d].begin(), dists[d].end(), 0LL);
    int total_zeros = total_count - total_ones;
    int make_ones = total_count - total_ones;
    int make_zeros = total_count - total_zeros;
    ans += min(make_ones, make_zeros);
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
