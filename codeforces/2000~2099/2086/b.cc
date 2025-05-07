#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0, x = 0;
  cin >> n >> k >> x;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<i64> p = {0};
  for (int i = 0; i < n; ++i) {
    p.push_back(p.back() + a[i]);
  }

  i64 total = p.back();
  i64 l = 0, r = k;
  i64 blocks = 0;
  while (l <= r) {
    i64 mid = l + (r-l) / 2;
    i64 block_sum = mid * total;
    if (block_sum < x) {
      l = mid + 1;
      blocks = mid;
    } else {
      r = mid - 1;
    }
  }


  i64 y = x - blocks * total;
  // cout << "y=" << y << endl;
  l = 0, r = n;
  i64 take_suffix = 0;
  while (l <= r) {
    i64 mid = l + (r - l) / 2;
    i64 suffix = p[n] - p[n-mid];
    if (suffix < y) {
      l = mid+1;
      take_suffix = mid;
    } else {
      r = mid-1;
    }
  }

  // cout << "blocks=" << blocks << ", take_suffix=" << take_suffix << endl;
  i64 ans = max(n * k - take_suffix - blocks * n, 0LL);
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
