#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;
  i64 all_even = k * 2;
  i64 all_odd = k;

  if (all_even <= n && (n - all_even) % 2 == 0) {
    vector<i64> ans(k, 2);
    i64 extra = n - all_even;
    ans.back() += extra;
    cout << "YES" << endl;
    for (int i = 0; i < k; ++i) {
      cout << ans[i] << " ";
    }
    cout << endl;
  } else if (all_odd <= n && (n - all_odd) % 2 == 0) {
    vector<i64> ans(k, 1);
    i64 extra = n - all_odd;
    ans.back() += extra;
    cout << "YES" << endl;
    for (int i = 0; i < k; ++i) {
      cout << ans[i] << " ";
    }
    cout << endl;
  } else {
    cout << "NO" << endl;
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
