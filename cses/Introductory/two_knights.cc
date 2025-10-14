#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

i64 get_placement_count(i64 n) {
  i64 grid_size = n * n;
  i64 total = grid_size * (grid_size-1) / 2;
  if (n >= 3) {
    i64 w = n-2+1, h = n - 3+1;
    i64 remove = w * h * 4;
    total -= remove;
  }
  return total;
}

void solve() {
  i64 n = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cout << get_placement_count(i) << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
