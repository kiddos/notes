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

  auto possible = [&](i64 s) -> bool {
    i64 current = 0;
    int groups = 1;
    for (int i = 0; i < n; ++i) {
      if (current + x[i] > s) {
        current = x[i];
        groups++;
      } else {
        current += x[i];
      }
    }
    return groups <= k;
  };

  i64 max_x = *max_element(x.begin(), x.end());
  i64 sum = accumulate(x.begin(), x.end(), 0LL);
  i64 l = max_x, r = sum;
  i64 ans = r;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
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

  solve();
  return 0;
}
