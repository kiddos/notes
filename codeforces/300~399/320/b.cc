#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  vector<pair<int,int>> intervals;

  auto valid = [&](int i1, int i2) -> bool {
    auto [a, b] = intervals[i1];
    auto [c, d] = intervals[i2];
    return (a > c && a < d) || (b > c && b < d);
  };

  auto bfs = [&](int a, int b) -> bool {
    int size = intervals.size();
    vector<bool> visited(size);
    queue<int> q;
    q.push(a);
    visited[a] = true;

    while (!q.empty()) {
      for (int s = q.size(); s > 0; --s) {
        int i1 = q.front();
        q.pop();

        if (i1 == b) {
          break;
        }

        for (int i2 = 0; i2 < size; ++i2) {
          if (visited[i2]) {
            continue;
          }
          if (valid(i1, i2)) {
            visited[i2] = true;
            q.push(i2);
          }
        }
      }
    }
    return visited[b];
  };

  for (int i = 0; i < n; ++i) {
    int t = 0;
    cin >> t;
    if (t == 1) {
      int x = 0, y = 0;
      cin >> x >> y;
      intervals.push_back({x, y});
    } else if (t == 2) {
      int a = 0, b = 0;
      cin >> a >> b;
      a--;
      b--;
      bool result = bfs(a, b);
      if (result) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
