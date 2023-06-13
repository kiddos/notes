#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  int num_queries = 0;
  cin >> num_queries;
  vector<array<int, 3>> railgun;
  for (int i = 0; i < num_queries; ++i) {
    int t = 0, d = 0, coord = 0;
    cin >> t >> d >> coord;
    railgun.push_back({t, d, coord});
  }

  vector<set<int>> horizontal(n+1);
  vector<set<int>> vertical(m+1);
  for (auto& [t, d, coord] : railgun) {
    if (d == 1) {
      horizontal[coord].insert(t);
    } else if (d == 2) {
      vertical[coord].insert(t);
    }
  }

  vector<vector<int>> delta = {{1, 0}, {0, 1}, {0, 0}};

  vector<vector<set<int>>> visited(n+1, vector<set<int>>(m+1));
  queue<array<int, 3>> q;
  q.push({0, 0, 0});
  visited[0][0].insert(0);

  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto [time, r, c] = q.front();
      q.pop();
      // cout << "visiting: " << time << " " << r << " " << c << endl;

      if (r == n && c == m) {
        cout << time << endl;
        return;
      }

      for (vector<int>& d : delta) {
        int r2 = r + d[0], c2 = c + d[1], t2 = time+1;
        if (r2 > n || c2 > m) continue;
        if (horizontal[r2].count(t2) || vertical[c2].count(t2)) continue;
        if (visited[r2][c2].size() > num_queries || visited[r2][c2].count(t2)) continue;
        visited[r2][c2].insert(t2);
        q.push({t2, r2, c2});
      }
    }
  }

  cout << "-1" << endl;
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
