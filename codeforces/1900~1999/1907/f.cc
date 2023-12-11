#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  auto is_inc = [&](int l, int r) -> bool {
    for (int i = l+1; i <= r; ++i) {
      if (a[i-1] > a[i]) return false;
    }
    return true;
  };
  
  if (is_inc(0, n-1)) {
    cout << "0" << endl;
    return;
  }

  auto is_dec = [&](int l, int r) -> bool {
    for (int i = l+1; i <= r; ++i) {
      if (a[i-1] < a[i]) {
        return false;
      }
    }
    return true;
  };

  if (is_dec(0, n-1)) {
    cout << "1" << endl;
    return;
  }

  constexpr int INF = 1000000000;
  auto is_shift_inc = [&]() -> int {
    for (int i = 1; i < n; ++i) {
      if (a[i-1] > a[i]) {
        if (is_inc(i, n-1) && a[n-1] <= a[0]) {
          return n-i; 
        } else {
          break;
        }
      }
    }
    return INF;
  };

  auto is_shift_dec = [&]() -> int {
    for (int i = 1; i < n; ++i) {
      if (a[i-1] < a[i]) {
        if (is_dec(i, n-1) && a[n-1] >= a[0]) {
          return n-i + 1;
        } else {
          break;
        }
      }
    }
    return INF;
  };

  int ans = min(is_shift_inc(), is_shift_dec());
  reverse(a.begin(), a.end());
  ans = min({ans, is_shift_inc()+1, is_shift_dec()+1});

  if (ans >= INF) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
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
