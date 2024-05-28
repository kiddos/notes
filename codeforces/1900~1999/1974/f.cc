#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0, n = 0, m = 0;
  cin >> a >> b >> n >> m;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }

  multiset<pair<int,int>> sx, sy;
  for (int i = 0; i < n; ++i) {
    pair<int,int> p1 = {x[i], y[i]};
    pair<int,int> p2 = {y[i], x[i]};
    sx.insert(p1);
    sy.insert(p2);
  }

  array<int,4> bounds = {1, 1, a, b};
  int turn = 0;
  vector<int> scores(2);
  for (int i = 0; i < m; ++i) {
    char c = '\0';
    int k = 0;
    cin >> c >> k;

    if (c == 'U') {
      bounds[0] += k;
      while (!sx.empty() && sx.begin()->first < bounds[0]) {
        auto [r, c] = *sx.begin();
        sx.erase(sx.begin());
        sy.erase(sy.find({c, r}));
        scores[turn]++;
      }
    } else if (c == 'D') {
      bounds[2] -= k;
      while (!sx.empty() && sx.rbegin()->first > bounds[2]) {
        auto [r, c] = *sx.rbegin();
        sx.erase(prev(sx.end()));
        sy.erase(sy.find({c, r}));
        scores[turn]++;
      }
    } else if (c == 'L') {
      bounds[1] += k;
      while (!sy.empty() && sy.begin()->first < bounds[1]) {
        auto [c, r] = *sy.begin();
        sy.erase(sy.begin());
        sx.erase(sx.find({r, c}));
        scores[turn]++;
      }
    } else if (c == 'R') {
      bounds[3] -= k;
      while (!sy.empty() && sy.rbegin()->first > bounds[3]) {
        auto [c, r] = *sy.rbegin();
        sy.erase(prev(sy.end()));
        sx.erase(sx.find({r, c}));
        scores[turn]++;
      }
    }

    turn ^= 1;
  }

  cout << scores[0] << " " << scores[1] << endl;
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
