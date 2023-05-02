#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> solve(vector<int>& x, vector<int>& y) {
  int n = x.size();
  map<pair<int, int>, int> m;
  for (int i = 0; i < n; ++i) {
    pair<int, int> p = {x[i], y[i]};
    m[p] = i;
  }

  vector<vector<int>> delta = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  queue<array<int, 3>> q;
  set<pair<int, int>> visited;
  for (int i = 0; i < n; ++i) {
    for (vector<int>& d : delta) {
      int x2 = x[i] + d[0], y2 = y[i] + d[1];
      if (!m.count({x2, y2})) {
        q.push({i, x2, y2});
        visited.insert({x[i], y[i]});
        break;
      }
    }
  }

  vector<pair<int, int>> ans(n);
  while (!q.empty()) {
    for (int size = q.size(); size > 0; --size) {
      auto [index, empty_x, empty_y] = q.front();
      q.pop();
      ans[index] = {empty_x, empty_y};
      for (vector<int>& d : delta) {
        pair<int, int> next_point = {x[index] + d[0], y[index] + d[1]};
        if (m.count(next_point) && !visited.count(next_point)) {
          q.push({m[next_point], empty_x, empty_y});
          visited.insert(next_point);
        }
      }
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n = 0;
  cin >> n;
  vector<int> x, y;
  for (int i = 0; i < n; ++i) {
    int xi = 0, yi = 0;
    cin >> xi >> yi;
    x.push_back(xi);
    y.push_back(yi);
  }

  vector<pair<int, int>> ans = solve(x, y);
  for (auto [x, y] : ans) {
    cout << x << ' ' << y << '\n';
  }
  cout.flush();
  return 0;
}
