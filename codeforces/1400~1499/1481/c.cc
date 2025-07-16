#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
  }
  vector<int> c(m+1);
  for (int i = 1; i <= m; ++i) {
    cin >> c[i];
  }

  vector<vector<int>> require(n+1);
  for (int i = n; i >= 1; --i) {
    if (b[i] != a[i]) {
      require[b[i]].push_back(i);
    }
  }

  vector<int> b_index(n+1);
  for (int i = 1; i <= n; ++i) {
    if (!b_index[b[i]]) {
      b_index[b[i]] = i;
    }
  }

  vector<int> need_to_replace;
  vector<int> ans(m+1);
  for (int j = 1; j <= m; ++j) {
    if (!require[c[j]].empty()) {
      ans[j] = require[c[j]].back();
      require[c[j]].pop_back();
      while (!need_to_replace.empty()) {
        ans[need_to_replace.back()] = ans[j];
        need_to_replace.pop_back();
      }
    } else {
      if (b_index[c[j]]) {
        while (!need_to_replace.empty()) {
          ans[need_to_replace.back()] = b_index[c[j]];
          need_to_replace.pop_back();
        }
        ans[j] = b_index[c[j]];
      } else{
        need_to_replace.push_back(j);
      }
    }
  }

  // cout << "need to replace:";
  // for (int idx : need_to_replace) {
  //   cout << idx << endl;
  // }

  if (!need_to_replace.empty()) {
    cout << "NO" << endl;
    return;
  }

  for (int i = 1; i <= n; ++i) {
    if (!require[i].empty()) {
      cout << "NO" << endl;
      return;
    }
  }

  cout << "YES" << endl;
  for (int i = 1; i <= m; ++i) {
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
