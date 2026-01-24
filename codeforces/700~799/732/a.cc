#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int k = 0, r = 0;
  cin >> k >> r;
  for (int i = 1; i <= 10; ++i) {
    if ((i * k) % 10 == r || (i * k) % 10 == 0) {
      cout << i << endl;
      break;
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
