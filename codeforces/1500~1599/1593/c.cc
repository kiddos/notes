#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> x(k);
  for (int i = 0; i < k; ++i) cin >> x[i];

  vector<i64> dist(k);
  for (int i = 0; i < k; ++i) {
    dist[i] = n - x[i];
  }
  sort(dist.begin(), dist.end());
  for (int i = 1; i < k; ++i) {
    dist[i] += dist[i-1];
  }
  int ans = upper_bound(dist.begin(), dist.end(), n-1) - dist.begin();
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
