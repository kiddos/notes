#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  if (n == 1) {
    cout << "1" << endl;
    cout << "1" << endl;
    return;
  }

  int left = k - 1, right = n - k;
  if (left % 2 == 1 && right % 2 == 1) {
    cout << "3" << endl;
    cout << "1 " << k << " " << k + 1 << endl;
  } else {
    if (k + 1 <= n && k-1 >= 1) {
      cout << "3" << endl;
      cout << "1 " << k-1 << " " << k+2 << endl;
    } else {
      cout << "-1" << endl;
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
