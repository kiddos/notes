#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i < n; ++i) {
    if (a[i] < a[i-1]) {
      cout << "0" << endl;
      return;
    }
  }

  ll ans = numeric_limits<int>::max();
  for (int i = 1; i < n; ++i) {
    ll diff = a[i] - a[i-1];
    if (diff % 2 == 0) {
      ans = min(ans, diff / 2 + 1);
    } else {
      ans = min(ans, (diff+1) / 2);
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
