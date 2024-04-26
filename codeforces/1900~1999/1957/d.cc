#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_BIT = 30;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  auto compute_msb = [&](int x) -> int {
    for (int b = MAX_BIT; b >= 0; --b) {
      if (x & (1<<b)) {
        return b;
      }
    }
    return 0;
  };

  vector<vector<int>> ones_prefix(MAX_BIT + 1, vector<int>(n + 2));
  vector<vector<int>> ones_suffix(MAX_BIT + 1, vector<int>(n + 2));
  vector<vector<int>> zeros_prefix(MAX_BIT + 1, vector<int>(n + 2));
  vector<vector<int>> zeros_suffix(MAX_BIT + 1, vector<int>(n + 2));
  for (int b = 0; b <= MAX_BIT; ++b) {
    for (int i = 1; i <= n; ++i) {
      if (a[i] & (1<<b)) {
        ones_prefix[b][i] = zeros_prefix[b][i-1] + 1;
        zeros_prefix[b][i] = ones_prefix[b][i-1];
      } else {
        ones_prefix[b][i] = ones_prefix[b][i-1];
        zeros_prefix[b][i] = zeros_prefix[b][i-1] + 1;
      }
    }
    for (int i = n; i >= 1; --i) {
      if (a[i] & (1<<b)) {
        ones_suffix[b][i] = zeros_suffix[b][i+1] + 1;
        zeros_suffix[b][i] = ones_suffix[b][i+1];
      } else {
        ones_suffix[b][i] = ones_suffix[b][i+1];
        zeros_suffix[b][i] = zeros_suffix[b][i+1] + 1;
      }
    }
  }

  i64 ans = 0;
  for (int i = 1; i <= n; ++i) {
    int m = compute_msb(a[i]);
    ans += 1LL * ones_prefix[m][i-1] * (1LL + zeros_suffix[m][i+1]);
    ans += 1LL * (1LL + zeros_prefix[m][i-1]) * ones_suffix[m][i+1];
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
