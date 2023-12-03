#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];

  auto possible = [&](int x0) -> bool {
    for (int i = 0; i < n; ++i) {
      int xi = x0 + i;
      if (abs(x[i] - xi) > 1) {
        return false;
      }
    }
    return true;
  };

  bool ans = possible(x[0]-1) || possible(x[0]) || possible(x[0]+1);
  if (ans) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
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
