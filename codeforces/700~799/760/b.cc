#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  auto possible = [&](i64 max_pillow) -> bool{
    i64 left = max(k - (max_pillow-1), 1LL);
    i64 right = min(k + (max_pillow-1), n);
    i64 left_count = max_pillow - (k - left);
    int right_count = max_pillow - (right - k);
    i64 sum = (left_count + max_pillow) * (max_pillow - left_count + 1) / 2 +
      (right_count + max_pillow) * (max_pillow - right_count + 1) / 2;
    sum -= max_pillow;
    sum += left-1;
    sum += n-right;
    return sum <= m;
  };

  i64 l = 1, r = m;
  i64 ans = 1;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    if (possible(mid)) {
      ans = mid;
      l = mid+1;
    } else {
      r = mid-1;
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
