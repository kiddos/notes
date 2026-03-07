#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  // 0  1 -> 1
  // 00 2 -> 1
  // 000 3 -> 1
  // 0x0x 4 -> 2
  // 0x0x0 5 -> 2
  // 0x00x0 6 -> 2
  // 0x00x0x 7 -> 3
  // 0x00x00x 8 -> 3
  // 0x00x00x0 9 -> 3
  // 0x00x00x0x 10 -> 4

  // 1001 2 -> 0
  // 10x01 3 -> 1
  // 100x01 4 -> 1
  // 100x001 5 -> 1
  // 100x00x01  7 -> 2
  // 100x00x001 8 -> 2
  // 100x00x0x01 9 -> 3
  // 100x00x00x01 10 -> 3

  // 10 1 -> 0
  // 10x 2 -> 1
  // 10x0 3 -> 1
  // 100x0 4 -> 1 
  // 100x0x 5 -> 2
  // 100x00x 6 -> 2
  // 100x00x0 7 -> 2
  // 100x00x0x 8 -> 3
  int n = 0;
  cin >> n;
  string s;
  cin >> s;
  int ans = 0;
  string all_zero(n, '0');
  if (s == all_zero) {
    ans = (n + 3 - 1) / 3;
  } else {
    int last = -1;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        if (last < 0) {
          int zeros = i - last - 1;
          int x = max(zeros-1, 0);
          ans += (x + 3 - 1) / 3;
        } else {
          int zeros = i - last - 1;
          int x = max(zeros-2, 0);
          ans += (x + 3 - 1) / 3;
        }

        last = i;
        ans++;
      }
    }
    int zeros = n-last-1;
    int x = max(zeros-1, 0);
    ans += (x + 3 - 1) / 3;
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
