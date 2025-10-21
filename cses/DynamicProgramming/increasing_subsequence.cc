#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  vector<int> dp;
  for (int i = 0; i < n; ++i) {
    auto it = lower_bound(dp.begin(), dp.end(), x[i]);
    if (it != dp.end()) {
      *it = x[i];
    } else {
      dp.push_back(x[i]);
    }
  }
  int ans = dp.size();
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
