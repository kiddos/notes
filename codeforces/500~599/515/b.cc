#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  int b = 0;
  cin >> b;
  vector<int> x(b);
  for (int i = 0; i < b; ++i) {
    cin >> x[i];
  }
  int g = 0;
  cin >> g;
  vector<int> y(g);
  for (int i = 0; i < g; ++i) {
    cin >> y[i];
  }

  vector<bool> boys(n), girls(m);
  for (int i = 0; i < b; ++i) {
    boys[x[i]] = true;
  }
  for (int i = 0; i < g; ++i) {
    girls[y[i]] = true;
  }

  int l = lcm(n, m);
  for (int t = 0; t < 2; ++t) {
    for (int i = 0; i < l; ++i) {
      int i1 = i % n, i2 = i % m;
      if (boys[i1] || girls[i2]) {
        boys[i1] = girls[i2] = true;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    if (!boys[i]) {
      cout << "No" << endl;
      return;
    }
  }

  for (int i = 0; i < m; ++i) {
    if (!girls[i]) {
      cout << "No" << endl;
      return;
    }
  }

  cout << "Yes" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
