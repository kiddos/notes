#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, bx = 0;
  cin >> n >> bx;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  int m = 0, by = 0;
  cin >> m >> by;
  vector<int> y(m);
  for (int i = 0; i < m; ++i) {
    cin >> y[i];
  }

  i64 x_val = 0;
  for (int i = 0; i < n; ++i) {
    x_val = x_val * bx + x[i];
  }
  i64 y_val = 0;
  for (int i = 0; i < m; ++i) {
    y_val = y_val * by + y[i];
  }
  if (x_val == y_val) {
    cout << "=" << endl;
  } else if (x_val < y_val) {
    cout << "<" << endl;
  } else if (x_val > y_val) {
    cout << ">" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
