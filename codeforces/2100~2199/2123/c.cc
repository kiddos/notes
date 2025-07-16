#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<bool> ans(n);
  for (int i = 0, min_so_far = numeric_limits<int>::max(); i < n; ++i) {
    min_so_far = min(min_so_far, a[i]);
    if (a[i] == min_so_far) {
      ans[i] = true;
    }
  }
  for (int i = n-1, max_so_far = numeric_limits<int>::min(); i >= 0; --i) {
    max_so_far = max(max_so_far, a[i]);
    if (a[i] == max_so_far) {
      ans[i] = true;
    }
  }
  for (int i = 0; i < n ; ++i) {
    cout << ans[i];
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
