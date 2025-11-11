#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  i64 ans = 0;
  int prefix_max = a[1];
  for (int i = 2; i <= n; ++i) {
    prefix_max = max(prefix_max, a[i]);
    if (i % 2 == 0) {
      a[i] = prefix_max;
      if (a[i] == a[i-1]) {
        a[i-1]--;
        ans++;
      }
    } else {
      if (a[i] >= a[i-1]) {
        ans += a[i] - a[i-1] + 1;
        a[i] = a[i-1] - 1;
      }
    }
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << a[i] << " ";
  // }
  // cout << endl;
  cout << ans <<endl;
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
