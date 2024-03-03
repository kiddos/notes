#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  for (int i = 1; i < n; ++i) {
    if (a[i] <= a[i-1]) {
      i64 k = (a[i-1] + a[i] - 1) / a[i];
      if (a[i] *k == a[i-1]) {
        k++;
      }
      a[i] *= k;
    }
  }
  cout << a.back() << endl;
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
