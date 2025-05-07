#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  i64 min_val = a[0];
  vector<i64> rhs;
  for (int i = 1; i < n; ++i) {
    if (a[i] == min_val) {
      cout << "YES" << endl;
      return;
    } else if (a[i] % min_val == 0) {
      rhs.push_back(a[i]);
    }
  }

  if (rhs.empty()) {
    cout << "NO" << endl;
    return;
  }

  i64 g = rhs[0];
  for (int i = 1; i < (int)rhs.size(); ++i) {
    g = gcd(g, rhs[i]);
  }

  if (g == min_val) {
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
