#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int a = 0, b = 0, n = 0;
  cin >> a >> b >> n;
  int turn = 0;
  while (true) {
    int g = 0;
    if (turn == 0) {
      // Simon
      g = gcd(n, a);
    } else {
      // Antisimon
      g = gcd(n, b);
    }
    if (g > n) {
      cout << 1-turn << endl;
      return;
    }
    n -= g;
    turn = 1-turn;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
