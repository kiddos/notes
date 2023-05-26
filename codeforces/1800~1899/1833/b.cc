#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n = 0, k = 0;
  cin >> n >> k;
  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<ll> b(n);
  for (int i = 0; i < n; ++i) cin >> b[i];

  vector<pair<ll, int>> temp;
  for (int i = 0; i < n; ++i) {
    temp.push_back({a[i], i});
  }
  sort(temp.begin(), temp.end());
  sort(b.begin(), b.end());

  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    auto [t, idx] = temp[i];
    ans[idx] = b[i];
  }

  for (int i = 0; i < n; ++i) cout << ans[i] << " ";
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
