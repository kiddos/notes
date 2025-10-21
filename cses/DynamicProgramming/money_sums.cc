#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  int total = accumulate(x.begin(), x.end(), 0LL);
  vector<bool> dp(total+1);
  dp[0] = true;
  for (int i = 0; i < n; ++i) {
    for (int val = total; val >= 0; --val) {
      if (dp[val]) {
        if (val + x[i] <= total) {
          dp[val+x[i]] = true;
        }
      }
    }
  }
  vector<int> ans;
  for (int i = 1; i <= total; ++i) {
    if (dp[i]) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
