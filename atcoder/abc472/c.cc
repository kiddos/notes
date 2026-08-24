#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  i64 k = 0;
  cin >> n >> m >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 window = 0;
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    if (i-m >= 0) {
      window -= ans[i-m] * a[i-m];
    }
    if (window + a[i] <= k) {
      window += a[i];
      ans[i] = 1;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (ans[i]) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
