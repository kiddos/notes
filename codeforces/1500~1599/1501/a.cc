#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1), b(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
  }
  vector<int> tm(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> tm[i];
  }

  i64 t = 0;
  for (int i = 1; i <= n; ++i) {
    int take = a[i] - b[i-1] + tm[i];
    t += take;
    if (i < n) {
      t += (b[i] - a[i]+1) / 2;
      t = max(t, (i64)b[i]);
    }
  }
  cout << t << endl;
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
