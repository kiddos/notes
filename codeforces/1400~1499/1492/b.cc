#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  vector<int> prefix_max(n);
  for (int i = 0, idx = 0; i < n; ++i) {
    if (p[i] >= p[idx]) {
      idx = i;
    }
    prefix_max[i] = idx;
  }

  vector<int> ans;
  int idx = n-1;
  while (idx >= 0) {
    int i2 = prefix_max[idx];
    for (int i = i2; i <= idx; ++i) {
      ans.push_back(p[i]);
    }
    idx = i2-1;
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
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
