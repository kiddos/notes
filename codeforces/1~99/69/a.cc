#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<array<int,3>> v(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> v[i][j];
    }
  }

  array<int,3> total = {0, 0, 0};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 3; ++j) {
      total[j] += v[i][j];
    }
  }

  if (total[0] == 0 && total[1] == 0 && total[2] == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
