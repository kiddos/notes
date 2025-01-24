#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, k = 0;
  cin >> n >> m >> k;

  if (n % 2 == 1) {
    k -= m / 2;
    n--;
  }
  if (m % 2 == 1) {
    m--;
  }
  int left = n * m / 2;
  if (k >= 0 && k % 2 == 0 && k <= left) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
