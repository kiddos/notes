#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(ll x, ll n, ll mod) {
  ll ans = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      ans *= x;
      ans %= mod;
    }

    n >>= 1;
    x = x * x;
    x %= mod;
  }
  return ans;
}

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  map<int, int> nums;
  for (int i = 0; i < n; ++i) {
    nums[a[i]]++;
  }

  vector<pair<int,int>> p(nums.begin(), nums.end());

  ll ans = 0;
  constexpr int MOD = 1e9 + 7;
  ll prod = 1;
  for (int i = 0, j = 0; i < p.size(); ++i) {
    prod *= p[i].second;
    prod %= MOD;
    while (j < p.size() && p[i].first - p[j].first >= m) {
      prod *= power(p[j].second, MOD-2, MOD);
      prod %= MOD;
      j++;
    }
    if (i-j+1 >= m) {
      ans += prod;
      ans %= MOD;
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
