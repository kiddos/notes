#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;

  int ans = 0;
  int loser = 0;
  int winner = n;
  while (winner > 1 || loser > 1) {
    if (loser > 1) {
      int played = loser / 2;
      loser -= played;
      ans += played;
    }

    if (winner > 1) {
      int played = winner / 2;
      ans += played;
      winner -= played;
      loser += played;
    }
  }
  ans++;
  cout << ans << endl;
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
