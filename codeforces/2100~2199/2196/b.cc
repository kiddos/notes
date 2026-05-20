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
  i64 ans = 0;
  int sq = sqrt(n);
  for (int i = 0; i < n; ++i) {
    if (a[i] >= sq) {
      i64 step = a[i];
      for (int j = i+step; j < n; j += step) {
        if (a[i] * a[j] == j-i) {
          ans++;
        }
      }
      for (int j = i-step; j >= 0; j -= step) {
        if (a[j] < sq && a[i] * a[j] == i-j) {
          ans++;
        }
      }
    } else {
      for (int val = 1; val < sq; ++val) {
        i64 j = i + a[i] * val;
        if (j < n && a[j] == val) {
          ans++;
        }
      }
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
