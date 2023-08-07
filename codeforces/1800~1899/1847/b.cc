#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int strength = ~0;
  for (int i = 0; i < n; ++i) {
    strength &= a[i];
  }

  if (strength > 0) {
    cout << "1" << endl;
    return;
  }

  int ans = 0;
  int s = ~0;
  for (int i = 0; i < n; ++i) {
    s &= a[i];
    if (s == strength) {
      ans++;
      s = ~0;
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
