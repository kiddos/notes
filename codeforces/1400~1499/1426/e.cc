#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(3);
  for (int i = 0; i < 3; ++i) {
    cin >> a[i];
  }
  vector<int> b(3);
  for (int i = 0; i < 3; ++i) {
    cin >> b[i];
  }

  vector<array<int,3>> possible = {
    {0, 1, 2},
    {0, 2, 1},
    {1, 0, 2},
    {1, 2, 0},
    {2, 0, 1},
    {2, 1, 0},
  };

  set<pair<int,int>> win = {{0, 1}, {1, 2}, {2, 0}};

  int ans1 = n, ans2 = 0;
  for (array<int,3> ordering1 : possible) {
    for (array<int,3> ordering2 : possible) {
      vector<int> c = a;
      vector<int> d = b;

      int total_win = 0;
      for (int k1 = 0; k1 < 3; ++k1) {
        for (int k2 = 0; k2 < 3; ++k2) {
          int take = min(c[ordering1[k1]], d[ordering2[k2]]);
          pair<int,int> p = {ordering1[k1], ordering2[k2]};
          c[ordering1[k1]] -= take;
          d[ordering2[k2]] -= take;
          if (win.count(p)) {
            total_win += take;
          }
        }
      }
      ans1 = min(ans1, total_win);
      ans2 = max(ans2, total_win);
    }
  }

  cout << ans1 << " " << ans2 << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
