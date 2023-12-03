#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  map<int, vector<int>> indices;
  for (int i = 0; i < n; ++i) {
    indices[a[i]].push_back(i);
  }

  int cond = 0;
  vector<int> ans(n);
  for (auto& [num, index]: indices) {
    if (index.size() == 1) {
      for (int idx : index) {
        ans[idx] = 1;
      }
    } else {
      if (cond == 0) {
        for (int idx : index) ans[idx] = 1;
        ans[index.back()] = 2;
        cond++;
      } else {
        for (int idx : index) ans[idx] = 2;
        ans[index.back()] = 3;
        cond++;
      }
    }
  }

  if (cond <= 1) {
    cout << "-1" << endl;
    return;
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
