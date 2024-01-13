#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << "0" << endl;
  } else if (n == 1 || m == 1) {
    cout << "1" << endl;
  } else {
    cout << "2" << endl;
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
