#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int max_msb = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0) {
      int m = 31 - __builtin_clz(a[i]);
      max_msb = max(max_msb, m);
    }
  }

  int max_val = 1 << (max_msb + 1);
  vector<vector<int>> x(max_val+1);
  for (int i = 0; i <= max_val; ++i) {
    x[i].push_back(0);
  }

  vector<int> range(max_val+1);
  for (int i = 0; i <= max_val; ++i) {
    range[i] = max_val;
  }

  vector<bool> found(max_val + 1);
  found[0] = true;
  for (int i = 0; i < n; ++i) {
    for (int y : x[a[i]]) {
      int x2 = y ^ a[i];
      found[x2] = true;

      while (range[x2] > a[i]) {
        if (range[x2] > a[i]) {
          x[range[x2]].push_back(x2);
        }
        --range[x2];
      }
    }
    x[a[i]].clear();
  }

  vector<int> ans;
  for (int i = 0; i <= max_val; ++i) {
    if (found[i]) {
      ans.push_back(i);
    }
  }

  cout << ans.size() << endl;
  for (int i = 0; i < (int) ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
