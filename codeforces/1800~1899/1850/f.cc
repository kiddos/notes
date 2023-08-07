#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;

  map<int,int> frogs;
  for (int i = 0; i < n; ++i) {
    int a = 0;
    cin >> a;
    frogs[a]++;
  }

  int ans = 0;
  for (int p = 1; p <= n; ++p) {
    set<int> factors;
    for (int d = 1; d * d <= p; ++d) if (p % d == 0) {
      factors.insert(d);
      factors.insert(p/d);
    }

    int total = 0;
    for (int f : factors) {
      total += frogs[f];
    }

    ans = max(ans, total);
  }

  cout << ans << endl;
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
