#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;
  int w = 0;
  cin >> w;
  vector<int> a(w);
  for (int i = 0; i < w; ++i) {
    cin >> a[i];
  }

  vector<i64> chance;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int top = max(i-k+1, 0), bot = min(i + k - 1, n-1);
      int left = max(j-k+1, 0), right = min(j+k-1, m - 1);
      i64 h = bot - top + 1 - (k - 1);
      i64 w = right - left + 1 - (k - 1);
      // cout << "w=" << w << ", h=" << h << endl;
      // cout << w * h << " ";
      chance.push_back(w * h);
    }
    // cout << endl;
  }

  sort(chance.rbegin(), chance.rend());
  sort(a.rbegin(), a.rend());
  i64 ans = 0;
  for (int i = 0; i < w; ++i) {
    ans += chance[i] * a[i];
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
