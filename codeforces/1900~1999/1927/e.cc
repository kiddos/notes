#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  vector<int> ans(n);
  int x = 1;
  for (int i = 0; i < k; ++i) {
    vector<int> indices;
    for (int j = i; j < n; j += k) {
      indices.push_back(j);
    }
    if (i % 2 == 1) {
      reverse(indices.begin(), indices.end());
    }
    for (int j : indices) {
      ans[j] = x++;
    }
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
