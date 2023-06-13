#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> x(n);
  for (int i = 0; i < n; ++i) cin >> x[i];
  vector<ll> y(n);
  for (int i = 0; i < n; ++i) cin >> y[i];

  vector<ll> z(n);
  for (int i = 0; i < n; ++i) {
    z[i] = y[i] - x[i];
  }

  sort(z.begin(), z.end());

  int l = 0, r = n-1;
  int ans = 0;
  while (l < r) {
    if (z[l] + z[r] < 0) {
      l++;
    } else {
      l++;
      r--;
      ans++;
    }
  }
  cout << ans << endl;
}

// [-3, 0, -8, 2, 1, 5]
// [-8, -3, 0, 1, 2, 5]

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
