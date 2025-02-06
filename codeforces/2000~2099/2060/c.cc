#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  int ans = 0;
  map<int,int> count;
  for (int i = 0; i < n; ++i) {
    count[x[i]]++;
  }
  for (auto [xi, ci] : count) {
    int yi = k-xi;
    if (yi == xi) {
      ans += ci/2;
    } else if (yi > xi) {
      if (count.count(yi)) {
        ans += min(ci, count[yi]);
      }
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
