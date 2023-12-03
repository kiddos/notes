#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<int> b(m);
  for (int i = 0; i < m; ++i) cin >> b[i];

  if (n % 2 == 0) {
    int bor = accumulate(b.begin(), b.end(), 0, [](int x, int y) { return x | y; });
    int max_a = accumulate(a.begin(), a.end(), 0, [&](int x, int y) { return x ^ y; });
    int min_a = max_a;
    for (int i = 0; i < 31; ++i) {
      if (bor & (1<<i)) {
        min_a = min_a & (~(1<<i));
      }
    }

    cout << min_a << " " << max_a << endl;
  } else {
    int min_a = accumulate(a.begin(), a.end(), 0, [&](int x, int y) { return x ^ y; });
    int bor = accumulate(b.begin(), b.end(), 0, [](int x, int y) { return x | y; });
    int max_a = min_a | bor;

    cout << min_a << " " << max_a << endl;
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
