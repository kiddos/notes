#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  i64 t = 0;
  cin >> n >> t;
  vector<i64> k(n);
  for (int i = 0; i < n; ++i) {
    cin >> k[i];
  }

  auto possible = [&](i64 time) -> bool {
    i64 total = 0;
    for (int i = 0; i < n; ++i) {
      total += time / k[i];
    }
    return total >= t;
  };

  i64 min_k = *min_element(k.begin(), k.end());
  i64 l = 0, r = min_k * t;
  i64 ans = r;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
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
