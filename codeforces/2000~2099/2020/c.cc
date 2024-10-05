#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 b = 0, c = 0, d = 0;
  cin >> b >> c >> d;
  i64 a = 0;
  for (int i = 0; i < 62; ++i) {
    i64 bit_b = b & (1LL<<i), bit_c = c & (1LL<<i);
    if (d & (1LL<<i)) {
      if (!bit_b && bit_c) {
        cout << "-1" << endl;
        return;
      }
      if (!bit_b && !bit_c) {
        a |= (1LL<<i);
      }
      // the other 2 case:
      // if both bit_b and bit_c is 1
      // bit_a can be zero
      // if bit_b is 1 and bit_c is 0
      // bit_a can be zero
    } else {
      if (bit_b && !bit_c) {
        cout << "-1" << endl;
        return;
      }

      if (bit_b && bit_c) {
        a |= (1LL<<i);
      } else if (!bit_b && bit_c) {
        a |= (1LL<<i);
      }
      // if bit_b and bit_c are both zero
      // bit_a can be zero
    }
  }
  cout << a << endl;
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
