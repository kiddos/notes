#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(k);
  for (int i = 0; i < k; ++i) {
    cin >> b[i];
  }
  sort(a.rbegin(), a.rend());
  sort(b.begin(), b.end());

  int i = 0, j = 0;
  i64 ans = 0;
  while (i < n) {
    if (j < k && i + b[j] <= n) {
      for (int c = 0; c < b[j] - 1; ++c, ++i) {
        ans += a[i];
      }
      i++;
      j++;
    } else {
      ans += a[i];
      i++;
    }
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
