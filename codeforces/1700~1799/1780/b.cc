#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; ++i) cin >> a[i];

    ll sum = accumulate(a.begin(), a.end(), 0LL);
    ll prefix = 0;
    ll ans = 0;
    for (int i = 0; i < n-1; ++i) {
      prefix += a[i];
      sum -= a[i];
      ll g = gcd(prefix, sum);
      ans = max(ans, g);
    }
    cout << ans << endl;
  }
  return 0;
}
