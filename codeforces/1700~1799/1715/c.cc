#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  ll n = 0, m = 0;
  cin >> n >> m;

  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  ll total = (n+1) * n / 2;
  for (ll i = 1; i <= n; ++i) {
    if (i > 0 && a[i] != a[i-1]) {
      total += (i-1) * (n-i+1);
    }
  }

  for (int q = 0; q < m; ++q) {
    int i = 0, x = 0;
    cin >> i >> x;

    ll remove = 0;
    ll add = 0;
    if (i > 1) {
      if (a[i] != a[i-1] && x == a[i-1]) {
        remove += (i-1) * (n-i+1);
      }
      if (a[i] == a[i-1] && x != a[i-1]) {
        add += (i-1) * (n-i+1);
      }
    }

    if (i < n) {
      if (a[i] != a[i+1] && x == a[i+1]) {
        remove += i * (n-i);
      }
      if (a[i] == a[i+1] && x != a[i+1]) {
        add += (i) * (n-i);
      }
    }

    a[i] = x;

    // cout << "add=" << add << ", remove=" << remove << endl;
    total += add;
    total -= remove;
    cout << total << endl;
  }

}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
