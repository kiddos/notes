#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  int size = n-k+1;
  vector<i64> window_sum(size);
  i64 sum = 0;
  for (int i = 0, j = 0; i < n; ++i) {
    sum += x[i];
    while (i - j+1 > k) {
      sum -= x[j];
      j++;
    }
    window_sum[j] = sum;
  }

  vector<pair<i64,int>> suffix_max(size);
  for (int i = size-1; i >= 0; --i) {
    suffix_max[i] = {window_sum[i], -i};
    if (i+1 < size) {
      suffix_max[i] = max(suffix_max[i], suffix_max[i+1]);
    }
  }

  array<i64,3> ans;
  for (int i = 0; i < size-k; ++i) {
    i64 total = window_sum[i] + suffix_max[i+k].first;
    int i1 = i+1;
    int i2 = -suffix_max[i+k].second + 1;
    array<i64,3> value = {total, -i1, -i2};
    ans = max(ans, value);
  }

  cout << -ans[1] << " " << -ans[2] << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
