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
  int max_a = *max_element(a.begin(), a.end());
  vector<int> count(max_a+1);
  for (int i = 0; i < n; ++i) {
    count[a[i]]++;
  }
  vector<i64> dp(max_a+3);
  for (int i = 0; i <= max_a; ++i) {
    dp[i+2] = max(dp[i+2], dp[i] + (i64)i * count[i]);
    dp[i+1] = max(dp[i+1], dp[i]);
  }
  i64 ans = *max_element(dp.begin(), dp.end());
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
