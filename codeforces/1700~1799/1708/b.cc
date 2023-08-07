#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;
  ll l = 0, r = 0;
  cin >> l >> r;

  vector<ll> ans;
  for (int i = 1; i <= n; ++i) {
    ll b = l / i;
    ll a1 = b * i, a2 = (b+1) * i;
    if (a1 >= l && a1 <= r) {
      ans.push_back(a1);
    } else if (a2 >= l && a2 <= r) {
      ans.push_back(a2);
    } else {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
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
