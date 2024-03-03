#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int k = 0, x = 0, a = 0;
  cin >> k >> x >> a;
  int lose = 0;
  for (int i = 0; i <= x; ++i) {
    // y * (k-1) > lose
    // y = (lose + k-1-1) / k-1
    int y = (lose + k-1) / (k-1);
    if (lose + y > a) {
      cout << "NO" << endl;
      return;
    }
    lose += y;
    // cout << "lose=" << lose << endl;;
  }
  cout << "YES" << endl;
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
