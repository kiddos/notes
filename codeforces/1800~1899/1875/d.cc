#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  map<int, int> freq;
  for (int i = 0; i < n; ++i) freq[a[i]]++;

  int mex = 0;
  while (freq.count(mex)) {
    mex++;
  }

  constexpr int INF = numeric_limits<int>::max();
  vector<i64> dp(mex+1, INF);
  dp.back() = 0;
  for (int i = mex; i >= 0; --i) {
    for (int j = 0; j < i; ++j) {
      dp[j] = min(dp[j], dp[i] + i * (freq[j] - 1) + j);
    }
  }
  // for (int i = 0; i <= mex; ++i) {
  //   cout << dp[i] << " ";
  // }
  // cout << endl;

  cout << dp[0] << endl;
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
