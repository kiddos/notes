#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

vector<int> get_factors(int x) {
  int s = sqrt(x);
  vector<int> f;
  for (int d = 1; d <= s; ++d) {
    if (x % d == 0) {
      f.push_back(d);
      if (d != 1) f.push_back(x/d);
    }
  }
  sort(f.rbegin(), f.rend());
  return f;
}

void solve() {
  int x = 0;
  cin >> x;
  vector<int> ans = {x};
  int p = 0;
  for (int i = 0; i < 32; ++i) {
    if (x & (1<<i)) {
      if (x == (1<<i)) {
        p = x;
        break;
      }
      x -= (1<<i);
      ans.push_back(x);
    }
  }

  while (p > 1) {
    p /= 2;
    ans.push_back(p);
  }

  cout << ans.size() << endl;
  for (int y : ans) cout << y << " ";
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
