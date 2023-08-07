#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0;
  cin >> n;
  
  vector<pair<ll,ll>> coords;
  for (int i = 0; i < n; ++i) {
    ll x = 0, y = 0;
    cin >> x >> y;
    coords.emplace_back(x, y);
  }

  map<ll,ll> x_count, y_count;
  ll ans = 0;
  for (auto& [x, y] : coords) {
    x_count[x]++;
    y_count[y]++;
  }

  for (auto& [y, c] : y_count) {
    ans += c * (c-1);
  }

  for (auto& [x, c] : x_count) {
    ans += c * (c-1);
  }

  y_count.clear();
  for (auto& [x, y] : coords) {
    ll y0 = y - x;
    y_count[y0]++;
  }

  for (auto& [y, c] : y_count) {
    ans += c * (c-1);
  }

  y_count.clear();

  for (auto& [x, y] : coords) {
    ll y0 = y + x;
    y_count[y0]++;
  }

  for (auto& [y, c] : y_count) {
    ans += c * (c-1);
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
