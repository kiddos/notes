#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<i64> p_sum = {0};
  for (int i = 0; i < n; ++i) {
    p_sum.push_back(p_sum.back() + a[i]);
  }
  vector<i64> p_max = a;
  for (int i = 1; i < n; ++i) {
    p_max[i] = max(p_max[i], p_max[i-1]);
  }

  vector<i64> ans;
  for (int i = n-1; i >= 0; --i) {
    if (i > 0) {
      i64 sum1 = p_sum[n] - p_sum[i];
      i64 sum2 = (p_sum[n] - p_sum[i+1]) + p_max[i-1];
      ans.push_back(max(sum1, sum2));
    } else {
      ans.push_back(p_sum[n] - p_sum[i]);
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << endl;
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
