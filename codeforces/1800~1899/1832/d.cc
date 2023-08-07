#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0, q = 0;
  cin >> n >> q;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());

  for (int i = 0; i < q; ++i) {
    int k = 0;
    cin >> k;

    vector<ll> b(n);
    for (int i = 0; i < n; ++i) {
      b[i] = a[i] + k;
      if (k > 0) k--;
    }

    if (k % 2 == 1) {
      k++;
      b[n-1] -= k;
    }
    k /= 2;

    sort(b.begin(), b.end());
    ll sum = accumulate(b.begin(), b.end(), 0LL) - k;
    ll ans = min(b[0], sum / n);
    cout << ans << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
