#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, x = 0;
  cin >> n >> x;
  int bits = bitset<32>(x).count();
  if (n == 1) {
    if (x == 0) {
      cout << "-1" << endl;
    } else {
      cout << x << endl;
    }
    return;
  } else if (n == 2) {
    if (bits > 1) {
      cout << x << endl;
    } else {
      int ans = x;
      if (x & 1) {
        ans += 4;
      } else {
        ans += 2;
      }
      cout << ans << endl;
    }
  } else {
    if (bits >= n) {
      cout << x << endl;
    } else {
      int add_one = n - bits;
      if (bits == 0) {
        if (n % 2 == 0) {
          cout << n << endl;
        } else {
          cout << (n-1) + 4 << endl;
        }
      } else if (bits == 1) {
        int ans = 0;
        if (n % 2 == 1) {
          ans = x + add_one;
        } else {
          add_one--;
          ans = x + add_one;
          if (x & 1) {
            ans += 4;
          } else {
            ans += 2;
          }
        }
        cout << ans << endl;
      } else {
        if (add_one % 2 == 1) {
          add_one++;
        }
        int ans = x + add_one;
        cout << ans << endl;
      }
    }
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
