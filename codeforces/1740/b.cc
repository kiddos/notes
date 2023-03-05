#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<pair<ll,ll>> cakes;
  for (int i = 0; i < n; ++i)  {
    int w = 0, h = 0;
    cin >> w >> h;
    if (w > h) swap(w, h);
    cakes.push_back({h, w});
  }

  sort(cakes.begin(), cakes.end());
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    auto [h, w] = cakes[i];
    ll perimeter = (w + h) * 2;
    ans += perimeter;
    if (i > 0) {
      ans -= min(cakes[i-1].first, h) * 2;
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
