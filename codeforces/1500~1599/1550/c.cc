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

  auto increasing = [&](int l, int r) -> bool {
    int len = r-l+1;
    vector<int> dp(len, 1);
    for (int i = l; i <= r; ++i) {
      for (int j = l; j < i; ++j) {
        if (a[j] <= a[i]) {
          dp[i-l] = max(dp[i-l], dp[j-l]+1);
          if (dp[i-l] >= 3) return true;
        }
      }
    }
    return false;
  };

  auto decreasing = [&](int l, int r) -> bool {
    vector<int> dp(4, 1);
    for (int i = l; i <= r; ++i) {
      for (int j = l; j < i; ++j) {
        if (a[j] >= a[i]) {
          dp[i-l] = max(dp[i-l], dp[j-l]+1);
          if (dp[i-l] >= 3) return true;
        }
      }
    }
    return false;
  };

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      ans++;
    } else if (i == 1) {
      ans += 2;
    } else {
      if (increasing(i-2, i) || decreasing(i-2, i)) {
        ans += 2;
      } else if (i >= 3 && (increasing(i-3, i) || decreasing(i-3, i))) {
        ans += 3;
      } else {
        ans += min(4, i+1);
      }
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
