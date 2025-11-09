#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> ans(n);
  ans[0] = 1;
  int x = 2;
  for (int i = 1; i < n; ++i) {
    i64 add = a[i] - a[i-1];
    if (add == i+1) {
      ans[i] = x++;
    } else {
      ans[i] = ans[i-add];
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
