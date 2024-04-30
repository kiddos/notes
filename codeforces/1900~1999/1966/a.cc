#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr int MAX_C = 100;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) cin >> c[i];

  vector<int> counts(MAX_C+1);
  for (int i = 0; i < n; ++i) {
    counts[c[i]]++;
  }
  int ans = n;
  for (int i = 1; i <= MAX_C; ++i) {
    if (counts[i] >= k) {
      ans = min(ans, k-1);
      break;
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
