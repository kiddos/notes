#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int m = 1;
  while ((1<<m) <= n) {
    for (int i = (1<<m)+1; i < min(n, (1<<(m+1))); ++i) {
      if (a[i] > a[i+1]) {
        cout << "NO" << endl;
        return;
      }
    }
    m++;
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
