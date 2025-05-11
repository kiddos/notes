#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  k--;
  if (n % 2 == 0) {
    k %= n;
    cout << k+1 << endl;
  } else {
    int collision = k / (n/2);
    k += collision;
    k %= n;
    cout << k+1 << endl;
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
