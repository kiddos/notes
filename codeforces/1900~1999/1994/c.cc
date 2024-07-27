#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 x = 0;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + a[i]);
  }

  auto find_greater = [&](int i) -> int {
    int ans = -1;
    int l = i, r = n-1;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      i64 sum = p[mid+1] - p[i];
      if (sum > x) {
        ans = mid;
        r = mid-1;
      } else {
        l = mid+1;
      }
    }
    return ans;
  };

  vector<i64> dp(n+1);
  for (int i = n-1; i >= 0; --i) {
    int j = find_greater(i);
    if (j >= i) {
      dp[i] = dp[j+1] + j-i;
    } else {
      dp[i] = n-i;
    }
  }

  i64 ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += dp[i];
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
