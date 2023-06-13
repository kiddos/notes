#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  ll p = 1;
  for (int i = 0; i < n; ++i) {
    p *= a[i];

    if (i < n-1) {
      a[i] = 1;
    } else {
      a[i] = p;
    }
  }

  ll ans = accumulate(a.begin(), a.end(), 0LL) * 2022;
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
