#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  i64 x = 0;
  cin >> n >> k >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<i64> p(n + 1);
  for (int i = 0; i < n; ++i) {
    p[i+1] = a[i] + p[i] - x;
  }

  i64 ans = 0;
  if (x >= 0) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < k && i+j+1 <= n; ++j) {
        i64 sum = p[i+j+1] - p[i] + x * (j+1) * 2LL;
        ans = max(ans, sum);
      }
    }
    i64 min_prefix = 0;
    for (int i = k; i < n; ++i) {
      i64 sum = p[i + 1] - min_prefix + 2LL * x * k;
      ans = max(ans, sum);
      min_prefix = min(min_prefix, p[i - k + 1]);
    }
  } else {
    i64 sum = 0;
    for (int i = 0; i + k < n; ++i) {
      sum = max(sum + a[i] - x, a[i] - x);
      ans = max(ans, sum);
    }
    sum = 0;
    for (int i = k; i < n; ++i) {
      sum = max(sum + a[i] - x, a[i] - x);
      ans = max(ans, sum);
    }

    int max_add = n-k;
    for (int r = n - k; r < n; ++r) {
      for (int l = 0; l <= r; ++l) {
        int len = r - l + 1;
        int sub = max(len - max_add, 0);
        i64 sum = p[r + 1] - p[l] + sub * x * 2;
        ans = max(ans, sum);
      }
    }
  }
  cout << ans << "\n";
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
