#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> p2;

void precompute() {
  ll p = 1;
  for (int i = 1; i < 32; ++i) {
    p2.push_back(p);
    p <<= 1;
  }
}

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<pair<int,ll>> ans;
  for (int i = 0; i < n; ++i) {
    ll closest = *lower_bound(p2.begin(), p2.end(), a[i]);
    ll x = a[i];
    while (x < closest) {
      ll add = min(x, closest-x);
      ans.push_back({i, add});
      x *= 2;
    }
  }

  cout << ans.size() << endl;
  for (auto& [index, add] : ans) {
    cout << index+1 << " " << add << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
