#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0;
  cin >> n;
  vector<int> digits = {2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = digits.size();
  int m = 1<<size;
  i64 divisable = 0;
  for (int mask = 1; mask < m; ++mask) {
    i64 l = 1;
    for (int b = 0; b < size; ++b) {
      if (mask & (1<<b)) {
        l = lcm(l, digits[b]);
      }
    }
    int count = bitset<10>(mask).count();
    if (count % 2 == 1) {
      divisable += n / l;
    } else {
      divisable -= n / l;
    }
  }
  i64 ans = n - divisable;
  // cout << divisable << endl;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
