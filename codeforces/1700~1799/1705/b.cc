#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  
  bool done = true;
  int zero = 0;
  ll ans = 0;
  for (int i = n-2; i >= 0; --i) {
    if (a[i]) {
      done = false;
      ans += zero;
      zero = 0;
    }

    if (a[i] == 0) {
      zero++;
    }
    ans += a[i];
  }

  if (done) {
    cout << "0" << endl;
    return;
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
