#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  int moves = (k == 1 || k == n) ? n-1 : n-1 + min(k-1, n-k);
  int pickup_coin = n;
  int throw_stone = n + 1;
  int ans = moves + pickup_coin + throw_stone;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
