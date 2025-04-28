#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

bool is_prime(int x) {
  if (x == 1) {
    return false;
  }
  for (int d = 2; d*d <= x; ++d) {
    if (x % d == 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  int x = 0, k = 0;
  cin >> x >> k;
  if (k > 1) {
    if (x != 1) {
      cout << "NO" << endl;
      return;
    } else {
      x = stoi(string(k, '1'));
      if (is_prime(x)) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  } else {
    if (is_prime(x)) {
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
