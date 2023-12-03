#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> K;
  int x = n;
  for (int d = 1; d*d <= x; ++d) {
    if (x % d == 0) {
      K.push_back(d);
      K.push_back(x / d);
    }
  }
  sort(K.begin(), K.end());
  K.erase(unique(K.begin(), K.end()), K.end());

  i64 ans = 0;
  for (int k : K) {
    i64 max_val = numeric_limits<i64>::min();
    i64 min_val = numeric_limits<i64>::max();
    for (int i = 0; i < n; i += k) {
      i64 sum = 0;
      for (int j = i; j < i+k; ++j) {
        sum += a[j];
      }
      max_val = max(max_val, sum);
      min_val = min(min_val, sum);
    }

    ans = max(ans, max_val - min_val);
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
