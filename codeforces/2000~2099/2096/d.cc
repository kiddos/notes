#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }

  map<int, vector<int>> ys;
  for (int i = 0; i < n; ++i) {
    ys[x[i]].push_back(y[i]);
  }
  int target_x = 0;
  for (auto& [xi, y_list] : ys) {
    if (y_list.size() % 2 == 1) {
      target_x = xi;
      break;
    }
  }

  map<int, vector<int>> diag;
  for (int i = 0; i < n; ++i) {
    int d = x[i] + y[i];
    diag[d].push_back(x[i]);
  }
  int target_y = 0;
  for (auto [d, x_list] : diag) {
    if (x_list.size() % 2 == 1) {
      target_y = d - target_x;
    }
  }

  cout << target_x << " " << target_y << endl;
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
