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

  vector<vector<int>> memo(n, vector<int>(2, -1));
  function<int(int,int)> dp = [&](int i, int s) -> int {
    if (i == (n-1) / 2) {
      if (n % 2 == 1) {
        return 0;
      } else {
        return a[i] == a[i+1] ? 1 : 0;
      }
    }
    
    if (memo[i][s] >= 0) {
      return memo[i][s];
    }

    int x = a[i], y = a[n-i-1];
    if (s) {
      swap(x, y);
    }

    int ans1 = dp(i+1, 0) + (x == a[i+1]) + (y == a[n-i-2]);
    int ans2 = dp(i+1, 1) + (x == a[n-i-2]) + (y == a[i+1]);
    return memo[i][s] = min(ans1, ans2);
  };

  int ans = min(dp(0, 0), dp(0, 1));
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
