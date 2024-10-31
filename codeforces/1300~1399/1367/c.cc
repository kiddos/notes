#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  string s;
  cin >> s;

  int ans = 0;
  if (s == string(n, '0')) {
    // p + (p-1) * k
    int l = 1, r = n;
    while (l <= r) {
      int mid = l + (r-l) / 2;
      int count = mid + (mid-1) * k;
      if (count <= n) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
  } else {
    int last = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        if (last == -1) {
          ans += i / (k+1);
        } else {
          i64 empty = i - last - 1;
          // p + (p+1) * k
          i64 l = 0, r = empty;
          i64 add = 0;
          while (l <= r) {
            i64 mid = l + (r-l) / 2;
            i64 count = mid + (mid+1) * k;
            if (count <= empty) {
              add = mid;
              l = mid + 1;
            } else {
              r = mid - 1;
            }
          }
          ans += add;
        }
        last = i;
      }
    }
    ans += (n-last-1) / (k+1);
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
