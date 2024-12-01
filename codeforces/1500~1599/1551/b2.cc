#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<vector<int>> c(n+1);
  for (int i = 0; i < n; ++i) {
    c[a[i]].push_back(i);
  }

  vector<int> full, rest;
  for (int i = 1; i <= n; ++i) {
    if ((int)c[i].size() >= k) {
      for (int j = 0; j < k; ++j) {
        full.push_back(c[i][j]);
      }
    } else {
      for (int idx : c[i]) {
        rest.push_back(idx);
      }
    }
  }

  vector<int> ans(n);
  for (int i = 0; i < (int)full.size(); ++i) {
    ans[full[i]] = (i % k) + 1;
  }
  int rest_size = rest.size() / k * k;
  for (int i = 0; i < rest_size; ++i) {
    ans[rest[i]] = (i % k) + 1;
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
