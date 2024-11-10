#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<i64> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  auto possible = [&](i64 k) -> bool {
    int i = 0;
    bool used = false;
    while (i < n) {
      if (i + 1 < n) {
        if (a[i+1] - a[i] <= k) {
          i += 2;
        } else {
          if (!used) {
            used = true;
            i++;
          } else {
            return false;
          }
        }
      } else {
        if (!used) {
          return true;
        } else {
          return false;
        }
      }
    }
    return true;
  };

  i64 l = 1, r = numeric_limits<i64>::max();
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

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
