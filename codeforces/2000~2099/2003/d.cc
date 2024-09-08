#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; ++i) {
    int l = 0;
    cin >> l;
    a[i] = vector<int>(l);
    for (int j = 0; j < l; ++j) {
      cin >> a[i][j];
    }
  }

  auto compute_mex = [&](vector<int>& arr) -> int {
    vector<int> b = arr;
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for (int i = 0; i < (int)b.size(); ++i) {
      if (b[i] != i) {
        return i;
      }
    }
    return (int) b.size();
  };

  i64 max_mex = 0;
  for (int i = 0; i < n; ++i) {
    i64 mex = compute_mex(a[i]);
    a[i].push_back(mex);
    i64 mex2 = compute_mex(a[i]);
    max_mex = max(max_mex, mex2);
  }

  if (m <= max_mex) {
    i64 ans = max_mex * (m+1);
    cout << ans << endl;
  } else {
    i64 ans = max_mex * (max_mex + 1) + (m + max_mex + 1) * (m - max_mex) / 2;
    cout << ans << endl;
  }
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
