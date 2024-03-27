#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

// 1, 3, 5, 7, 9, 11, 13, 15, 17, 19
// 2, 6, 10, 14, 18, 22, 26, 30, 34, 38
// 4, 12, 20, 28, 36, 42, 50, 58,

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;

  i64 l = log(n) / log(2);
  for (i64 x = 1, base = 2; x-1 <= l; ++x, base *= 2) {
    i64 row = (n+base/2) / base;
    // cout << "row size=" << row << endl;
    // cout << "k=" << k << endl;
    if (k <= row) {
      cout << k * base - base/2 << endl;
      return;
    }
    k -= row;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}