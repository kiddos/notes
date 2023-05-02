#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

void solve() {
  int n = 0;
  cin >> n;

  vector<pair<ll,ll>> candy;
  for (int i = 0; i < n; ++i) {
    ll a = 0, b = 0;
    cin >> a >> b;
    candy.push_back({a, b});
  }

  ll g = -1;
  ll div = 1;
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    auto [a, b] = candy[i];
    if (g < 0) {
      g = a * b;
    } else {
      g = gcd(g, a * b);
    }
    div = lcm(div, b);

    // cout << "g=" << g << ", div=" << div << endl;
    if (g % div != 0) {
      g = a * b;
      div = b;
      ans++;
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
