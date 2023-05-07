#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());
  int ans = -1;
  for (int i = 0; i < n; ++i) {
    int liars = n-i-1;
    if (liars >= a[i]) {
      ans = liars;
    }
  }
  int truth = 0;
  for (int i = 0; i < n; ++i) {
    if (ans >= a[i]) {
      truth++;
    }
  }

  if (n-truth != ans) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
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
