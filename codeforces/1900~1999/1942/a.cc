#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  if (k == 1) {
    for (int i = 0; i < n; ++i) {
      cout << i+1 << " ";
    }
    cout << endl;
  } else if (k == n) {
    for (int i = 0; i < n; ++i) {
      cout << "1 ";
    }
    cout << endl;
  } else {
    cout << "-1" << endl;
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
