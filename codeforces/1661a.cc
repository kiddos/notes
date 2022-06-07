#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(vector<ll>& a, vector<ll>& b) {
  int n = a.size();
  ll ans = 0;
  for (int i = 1; i < n; ++i) {
    if (llabs(a[i] - b[i-1]) + llabs(b[i] - a[i-1]) < llabs(a[i] - a[i-1]) + llabs(b[i] - b[i-1])) {
      swap(a[i], b[i]);
    }
    ans += llabs(a[i] - a[i-1]) + llabs(b[i] - b[i-1]);
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    ll ans = solve(a, b);
    cout << ans << '\n';
  }
  cout.flush();
  return 0;
}
