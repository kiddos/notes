#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int solve(vector<ll>& a, ll x) {
  map<ll, int> count;
  for (int e : a) count[e]++;
  int ans = 0;
  for (auto it = count.begin(); it != count.end(); ++it) {
    if (it->second == 0) continue;
    ll pair = it->first * x;
    if (!count.count(pair)) {
      ans += it->second;
    } else {
      if (it->second <= count[pair]) {
        count[pair] -= it->second;
      } else {
        ans += it->second - count[pair];
        count[pair] = 0;
      }
    }
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, x = 0;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ans = solve(a, x);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
