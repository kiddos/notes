#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  if (n <= 4) {
    cout << "-1" << endl;
  } else if (n == 5) {
    cout << "1 3 5 4 2" << endl;
  } else if (n == 6) {
    cout << "1 3 5 4 2 6" << endl;
  } else if (n == 7) {
    cout << "7 1 3 5 4 2 6" << endl;
  } else {
    for (int i = (n % 2 == 1 ? n : n - 1); i >= 1; i -= 2) {
      cout << i << " ";
    }
    cout << "8 ";
    for (int i = 2; i <= n; i += 2) {
      if (i == 8) continue;
      cout << i << " ";
    }
    cout << endl;
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
