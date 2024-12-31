#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

pair<int,int> find(vector<string>& s, int n, int m, char ch) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == ch) {
        return {i, j};
      }
    }
  }
  return {-1, -1};
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  auto start = find(s, n, m, 'S');
  auto target = find(s, n, m, 'T');

  constexpr int inf = numeric_limits<int>::max();
  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(16, inf)));
  priority_queue<array<int,5>, vector<array<int,5>>, greater<>> pq;
  pq.push({0, start.first, start.second, 0, 0});
  for (int k = 0; k < 4; ++k) {
    dist[start.first][start.second][k * 4] = 0;
  }
  while (!pq.empty()) {
    auto [dist0, r, c, k0, step0] = pq.top();
    pq.pop();

    if (r == target.first && c == target.second) {
      break;
    }

    for (int k = 0; k < 4; ++k) {
      vector<int>& d = delta[k];
      int r2 = r + d[0], c2 = c + d[1];
      if (r2 < 0 || r2 >= n || c2 < 0 || c2 >= m) continue;
      if (s[r2][c2] == '#') continue;

      int dist1 = dist0 + 1;
      int step2 = k == k0 ? step0 + 1 : 1;
      if (step2 > 3) {
        step2 = 2;
        dist1 = dist0 + 3;
      }
      if (dist1 < dist[r2][c2][k * 4 + step2]) {
        dist[r2][c2][k * 4 + step2] = dist1;
        pq.push({dist1, r2, c2, k, step2});
      }
    }
  }

  int ans = inf;
  for (int k = 0; k < 4; ++k) {
    for (int step = 1; step <= 3; ++step) {
      // cout << "k=" << k << ", step=" << step << " dist=" << dist[target.first][target.second][k * 4 + step] << endl;
      ans = min(ans, dist[target.first][target.second][k * 4 + step]);
    }
  }
  if (ans == inf) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
