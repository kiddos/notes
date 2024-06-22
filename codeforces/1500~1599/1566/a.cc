#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, s = 0;
  cin >> n >> s;
  int m = n % 2 == 1 ? (n+1) / 2 : (n / 2) + 1;
  int x = s / m;
  cout << x << endl;
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
