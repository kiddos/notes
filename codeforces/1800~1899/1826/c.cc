#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;

  set<int> divisors;
  int x = n;
  for (int d = 2; d*d <= x; ++d) {
    if (x % d == 0) {
      while (x % d == 0) {
        x /= d;
      }
      divisors.insert(d);
    }
  }
  if (x > 1) {
    divisors.insert(x);
  }

  for (int d : divisors) {
    if (d <= m) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
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
