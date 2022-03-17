#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(int n, int m, vector<pair<int, int>>& colors, ll k) {
  if (k == 1) return 1;
  const int MOD = 998244353;

  ll ans = 1;
  unordered_set<int> x, y;
  for (int i = colors.size()-1; i >= 0; --i) {
    bool can_add = false;
    if (!x.count(colors[i].first)) {
      x.insert(colors[i].first);
      can_add = true;
    }
    if (!y.count(colors[i].second)) {
      y.insert(colors[i].second);
      can_add = true;
    }

    if (can_add) {
      ans *= k;
      ans %= MOD;
    }

    if (x.size() == n || y.size() == m) break;
  }
  return ans;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t = 0;
  cin >> t;
  while (t-- > 0) {
    int n = 0, m = 0, k = 0, q = 0;
    cin >> n >> m >> k >> q;
    vector<pair<int, int>> colors(q);
    for (int i = 0; i < q; ++i) cin >> colors[i].first >> colors[i].second;
    ll ans = solve(n, m, colors, k);
    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
