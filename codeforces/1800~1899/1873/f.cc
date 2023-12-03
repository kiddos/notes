#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 k = 0;
  cin >> n >> k;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<i64> h(n);
  for (int i = 0; i < n; ++i) cin >> h[i];

  i64 current = 0;
  deque<i64> added;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i == 0 || h[i-1] % h[i] != 0) {
      current = a[i];
      added.clear();
      added.push_back(a[i]);
    } else {
      current += a[i];
      added.push_back(a[i]);
    }

    while (current > k && !added.empty()) {
      current -= added.front();
      added.pop_front();
    }

    ans = max(ans, (int)added.size());
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
