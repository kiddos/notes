#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n = 0, m = 0;
  cin >> n >> m;
  ll val = m / n;
  vector<ll> a(n, val);
  ll total = val * n;
  if (total < m) {
    ll left = m - total;
    if (n % 2 == 1) {
      a.back() += left;
    } else {
      if (left % 2 == 0) {
        a[n-1] += left / 2;
        a[n-2] += left / 2;
      } else {
        cout << "NO" << endl;
        return;
      }
    }
  }

  for (int i = 0; i < n; ++i) if (a[i] == 0) {
    cout << "NO" << endl;
    return;
  }

  cout << "YES" << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
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
