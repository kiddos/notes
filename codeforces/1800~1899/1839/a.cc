#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  if (k == 1) {
    cout << n << endl;
  } else if (n % k == 1) {
    cout << (n+k-1) / k << endl;
  } else {
    cout << (n+k-1) / k + 1 << endl;
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
