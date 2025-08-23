#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, c = 0;
  cin >> n >> c;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  auto possible = [&](int idx) -> bool {
    i64 p = 1;
    for (int i = idx; i >= 0; --i) {
      i64 weight = a[i] * p;
      if (weight > c) {
        return false;
      }
      p *= 2;
    }
    return true;
  };

  int l = 0, r = n-1;
  int idx = -1;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    if (possible(mid)) {
      idx = mid;
      l = mid+1;
    } else {
      r = mid-1;
    }
  }
  int ans = n-idx-1;
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
