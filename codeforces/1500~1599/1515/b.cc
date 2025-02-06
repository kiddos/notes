#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_power2(int x) {
  while (x % 2 == 0) {
    x /= 2;
  }
  return x == 1;
}

void solve() {
  int n = 0;
  cin >> n;
  if (n == 1) {
    cout << "NO" << endl;
  } else if (is_power2(n)) {
    cout << "YES" << endl;
  } else {
    bool div = false;
    int x = n;
    while (x % 2 == 0) {
      x /= 2;
      div = true;
    }

    int sq = sqrt(x);
    if (sq * sq == x && div) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
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
