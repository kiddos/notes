#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int x = 0;
  cin >> x;

  i64 l = 1, r = 1e6;
  i64 step = r;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 sum = (mid + 1) * mid / 2;
    if (sum >= x) {
      step = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }

  i64 sum = (step+1) * step / 2;
  if (x == sum) {
    cout << step << endl;
    return;
  }

  i64 high = sum-2;
  i64 low = sum-step-1;
  if (low <= x && x <= high) {
    cout << step << endl;
  } else {
    cout << step+1 << endl;
  }
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
