#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void place(int r, int c, int color) {
  cout << color << " " << r << " " << c << endl;
}

void solve() {
  int n = 0;
  cin >> n;

  vector<vector<pair<int,int>>> squares(2);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int p = (i+j) % 2;
      squares[p].push_back({i+1, j+1});
    }
  }

  int t = n*n;
  for (int i = 0; i < t; ++i) {
    int a = 0;
    cin >> a;
    if (a == 1) {
      if (!squares[0].empty()) {
        auto [r, c] = squares[0].back();
        squares[0].pop_back();
        place(r, c, 3);
      } else {
        auto [r, c] = squares[1].back();
        squares[1].pop_back();
        place(r, c, 2);
      }
    } else if (a == 2) {
      if (!squares[0].empty()) {
        auto [r, c] = squares[0].back();
        squares[0].pop_back();
        place(r, c, 3);
      } else {
        auto [r, c] = squares[1].back();
        squares[1].pop_back();
        place(r, c, 1);
      }
    } else if (a == 3) {
      if (!squares[1].empty()) {
        auto [r, c] = squares[1].back();
        squares[1].pop_back();
        place(r, c, 1);
      } else {
        auto [r, c] = squares[0].back();
        squares[0].pop_back();
        place(r, c, 2);
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
