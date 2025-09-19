#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n ; ++i) {
    cin >> a[i];
  }

  auto is_hill = [&](int i) -> bool {
    if (i <= 0 || i >= n-1) {
      return false;
    }
    return a[i] > a[i-1] && a[i] > a[i+1];
  };

  auto is_valley = [&](int i) -> bool {
    if (i <= 0 || i >= n-1) {
      return false;
    }
    return a[i] < a[i-1] && a[i] < a[i+1];
  };

  auto get_val = [&](int i) -> int {
    if (is_hill(i) || is_valley(i)) {
      return 1;
    }
    return 0;
  };

  vector<int> val(n);
  for (int i = 1; i < n-1; ++i) {
    val[i] = get_val(i);
  }

  vector<int> prefix = val, suffix = val;
  for (int i = 1; i < n; ++i) {
    prefix[i] += prefix[i-1];
  }
  for (int i = n-2; i >= 0; --i) {
    suffix[i] += suffix[i+1];
  }

  int ans = prefix.back();
  for (int i = 0; i < n; ++i) {
    int p = i >= 2 ? prefix[i-2] : 0;
    int s = i+2 < n ? suffix[i+2] : 0;
    int ai = a[i];

    if (i > 0) {
      a[i] = a[i-1];
      int middle = get_val(i-1) + get_val(i) + get_val(i+1);
      ans = min(ans, p + s + middle);
    }
    
    if (i+1 < n) {
      a[i] = a[i+1];
      int middle = get_val(i-1) + get_val(i) + get_val(i+1);
      ans = min(ans, p + s + middle);
    }

    a[i] = ai;
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
