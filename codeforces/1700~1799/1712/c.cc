#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<vector<int>> index(n+1);
  for (int i = 0; i < n; ++i) {
    index[a[i]].push_back(i);
  }

  auto good = [&](int val) {
    for (int i : index[val]) {
      if ((i-1 >= 0 && a[i-1] > a[i]) || (i+1 < n && a[i+1] < a[i])) return false;
    }
    return true;
  };

  int ans = 0;
  for (int val = n; val >= 1; --val) {
    if (!good(val)) {
      for (int i : index[val]) {
        a[i] = 0;
      }
      ans++;
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
