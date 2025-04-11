#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 sum = accumulate(a.begin(), a.end(), 0LL);
  i64 min_val = (sum + x - 1) / x;
  i64 max_val = 0;
  for (int i = 0; i < n; ++i) {
    max_val += (a[i] + x - 1) / x;
  }
  cout << min_val << " " << max_val << endl;
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
