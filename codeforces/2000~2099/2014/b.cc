#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  int odd_count = 0;
  if (k % 2 == 1) {
    if (n % 2 == 1) {
      odd_count = (k+1) / 2;
    } else {
      odd_count = (k-1) / 2;
    }
  } else {
    odd_count = k / 2;
  }

  if (odd_count % 2 == 0) {
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
