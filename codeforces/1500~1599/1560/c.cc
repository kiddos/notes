#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int k = 0;
  cin >> k;
  int l = 1, r = 1000000000;
  i64 c = 1;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 count = (1 + mid * 2 - 1) * mid / 2;
    if (count >= k) {
      c = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }
  i64 prev = (1 + (c-1) * 2 - 1) * (c-1) / 2;
  k -= prev;
  if (k <= c) {
    cout << k << " " << c << endl;
  } else {
    k -= c;
    cout << c << " " << c - k << endl;
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
