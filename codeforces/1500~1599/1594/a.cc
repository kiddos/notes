#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

constexpr i64 MAX_N = 1000000000000000000;

// (l + l + 4) * 5 / 2 = MAX_N
// (2 * l + 4) * 5 / 2 = MAX_N
// 10 * l + 20 = 2 * MAX_N
// l = (2 * MAX_N - 20) / 10

void solve() {
  i64 n = 0;
  cin >> n;

  if (n == MAX_N || n == -MAX_N) {
    i64 l = (2 * MAX_N - 20) / 10;
    i64 r = l + 4;
    cout << l << " " <<  r << endl;
  } else {
    cout << -(n-1)  << " " << n << endl;
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
