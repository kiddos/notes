#include <bits/stdc++.h>

using namespace std;

using i64 = long long;


void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  auto possible = [&](int len) -> bool {
    bitset<3000> dp;
    for (int i = 0; i <= len; ++i) {
      dp.set(i);
    }
    bitset<3000> mask = dp;
    for (int i = 0; i < n; ++i) {
      dp = ((dp >> a[i]) | (dp << a[i])) & mask;
    }
    return dp.any();
  };

  int max_len = *max_element(a.begin(), a.end()) * 2;
  int l = 0, r = max_len;
  int ans = r;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    if (possible(mid)) {
      ans = mid;
      r = mid-1;
    } else {
      l = mid+1;
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
