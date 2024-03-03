#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 n = 0, k = 0;
  cin >> n >> k;
  // color one cell gets 2 diagnal?
  int p = n + n - 2;
  if (k <= p*2) {
    cout << (k+1) / 2 << endl;
  } else {
    cout << p + k-p*2 << endl;
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
