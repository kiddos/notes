#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;
  // 3, 5, 7, 8, 9, 11, 12, 13, 15, 16, 17, 19, 20, 21, 23, 24
  // 25, 27, 28, 29, 31, 32, 33, 35, 36, 37, 39
  int l = 1, r = numeric_limits<int>::max();
  int ans = r;
  while (l <= r) {
    int mid = l + (r-l) / 2;
    int count_odd = max((mid + 1) / 2 - 1, 0);
    int count_mul4 = max(mid / 4 - 1, 0);
    int total = count_odd + count_mul4;
    // cout << "count odd=" << count_odd << ", count multiple of 4 =" << count_mul4 << endl;
    if (total >= n) {
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
