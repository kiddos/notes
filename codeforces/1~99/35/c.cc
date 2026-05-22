#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  ifstream input("input.txt");

  int n = 0, m = 0;
  input >> n >> m;
  int k = 0;
  input >> k;
  vector<int> x(k), y(k);
  for (int i = 0; i < k; ++i) {
    input >> x[i] >> y[i];
  }
  queue<pair<int,int>> q;
  vector<vector<bool>> visited(n+1, vector<bool>(m+1));
  pair<int,int> ans;
  for (int i = 0; i < k; ++i) {
    q.push({x[i], y[i]});
    visited[x[i]][y[i]] = true;
  }

  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto [xi, yi] = q.front();
      q.pop();
      ans = {xi, yi};
      for (vector<int>& d : delta) {
        int x2 = xi + d[0], y2 = yi + d[1];
        if (x2 < 1 || x2 > n || y2 < 1 || y2 > m) {
          continue;
        }
        if (visited[x2][y2]) {
          continue;
        }
        visited[x2][y2] = true;
        q.push({x2, y2});
      }
    }
  }

  ofstream output("output.txt");
  output << ans.first << " " << ans.second << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
