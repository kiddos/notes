#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  int l = 1, r = n;
  vector<int> ans;
  while ((int)ans.size() < n) {
    for (int i = 1; i < k && l <= r; ++i) {
      ans.push_back(r--);
    }
    if (l <= r) {
      ans.push_back(l++);
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
