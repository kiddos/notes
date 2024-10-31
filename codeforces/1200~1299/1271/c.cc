#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, sx = 0, sy = 0;
  cin >> n >> sx >> sy;

  vector<int> x(n), y(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
  }

  int north = 0, south = 0, east = 0, west = 0;
  for (int i = 0; i < n; ++i) {
    if (y[i] > sy) {
      north++;
    }
    if (y[i] < sy) {
      south++;
    }
    if (x[i] > sx) {
      east++;
    }
    if (x[i] < sx) {
      west++;
    }
  }

  vector<array<int, 3>> p = {
    {north, sx, sy+1},
    {south, sx, sy-1},
    {east, sx+1, sy},
    {west, sx-1, sy},
  };
  sort(p.begin(), p.end());

  auto valid = [](int x) -> bool {
    return x >= 0 && x <= 1000000000;
  };

  while (!p.empty() && (!valid(p.back()[0]) || !valid(p.back()[1]))) {
    p.pop_back();
  }

  int tx = p.back()[1], ty = p.back()[2];
  cout << p.back()[0] << endl;
  cout << tx << " " << ty << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
