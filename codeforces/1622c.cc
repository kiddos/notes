#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll floor(ll a, ll b) {
	ll val = a / b;
	while (val * b > a)
		val--;
	return val;
}

ll solve(vector<int>& a, ll k) {
  int n = a.size();
  sort(a.begin(), a.end());
  ll total = accumulate(a.begin(), a.end(), 0LL);
  ll ans = max(total - k, 0LL);
  vector<ll> prefix_sum  = {0};
  for (int aa : a) prefix_sum.push_back(aa + prefix_sum.back());
  for (int y = 0; y < n; ++y) {
    // ll x = a[0] - floor((k - prefix_sum[n-y] + a[0]) / (y+1));
    ll x = a[0] - floor((k - prefix_sum[n-y] + a[0]), (y+1));
    // cout << y + max(x, 0LL) << " ";
    ans = min(ans, y + max(x, 0LL));
  }
  // cout << endl;
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t--) {
    int n = 0;
    ll k = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int ans = solve(a, k);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
