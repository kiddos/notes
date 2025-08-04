#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  vector<char> s(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  vector<array<int, 3>> robots;
  for (int i = 0; i < n; ++i) {
    // L: 0
    // R: 1
    robots.push_back({x[i], i, s[i] == 'L' ? 0 : 1});
  }
  sort(robots.begin(), robots.end());

  vector<int> ans(n, -1);
  deque<array<int,3>> st[2];
  for (int k = 0; k < n; ++k) {
    auto [xi, i, si] = robots[k];
    int p = xi % 2;
    if (si == 0 && !st[p].empty() && st[p].back()[2] == 1) {
      auto [xj, j, sj] = st[p].back();
      st[p].pop_back();
      int mid = (xi + xj) / 2;
      int t = xi - mid;
      ans[i] = ans[j] = t;
    } else {
      st[p].push_back(robots[k]);
    }
  }

  for (int p = 0; p < 2; ++p) {
    // cout <<"p=" << p << endl;
    // for (auto [xi, i, si] : st[p]) {
    //   cout << xi << "," << i << "," << si << endl;
    // }

    while (st[p].size() >= 2) {
      auto [xi, i, si] = st[p].front();
      st[p].pop_front();
      auto [xj, j, sj] = st[p].front();
      st[p].pop_front();
      if (si == 0 && sj == 0) {
        int move = xi;
        int x2 = xj - move;
        int mid = (x2 + 1) / 2;
        int t = move + x2 - mid;
        ans[i] = ans[j] = t;
      } else {
        st[p].push_front({xj, j, sj});
        st[p].push_front({xi, i, si});
        break;
      }
    }

    while (st[p].size() >= 2) {
      auto [xi, i, si] = st[p].back();
      st[p].pop_back();
      auto [xj, j, sj] = st[p].back();
      st[p].pop_back();
      if (sj == 1 && si == 1) {
        int move = m - xj;
        int x2 = xi + move;
        int mid = (m + x2) / 2;
        int t = move + mid - x2;
        ans[i] = ans[j] = t;
      } else {
        st[p].push_back({xj, j, sj});
        st[p].push_back({xi, i, si});
        break;
      }
    }

    if (st[p].size() == 2) {
      auto [xi, i, si] = st[p].front();
      auto [xj, j, sj] = st[p].back();
      // first is going left, second is going right
      int d1 = xi, d2 = m - xj;
      int move = max(d1, d2);
      int x1 = xi - move, x2 = xj + move;
      if (x1 < 0) {
        x1 = -x1;
      }
      if (x2 > m) {
        x2 = m - (x2 - m);
      }
      int mid = (x1 + x2) / 2;
      int t = move + mid - x1;
      ans[i] = ans[j] = t;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
