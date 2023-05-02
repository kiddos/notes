#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  ll even = 0, odd = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 1) odd++;
    else even++;
  }

  ll ans = accumulate(a.begin(), a.end(), 0LL);
  for (int i = 0; i < q; ++i) {
    int type = 0;
    ll x = 0;
    cin >> type >> x;
    if (type == 0) {
      ans += even * x;
      if (x % 2 == 1) {
        odd += even;
        even = 0;
      }
    } else if (type == 1) {
      ans += odd * x;
      if (x % 2 == 1) {
        even += odd;
        odd = 0;
      }
    }

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
