#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, int rb, int cb, int rd, int cd) {
  int dr = 1, dc = 1;
  int t = 0;
  while (rb != rd && cb != cd) {
    if (rb + dr > n || rb + dr < 1) dr = -dr;
    if (cb + dc > m || cb + dc < 1) dc = -dc;
    rb += dr;
    cb += dc;
    t++;
  }
  return t;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0, m = 0, rb = 0, cb = 0, rd = 0, cd = 0;
    cin >> n >> m >> rb >> cb >> rd >> cd;
    int ans = solve(n, m, rb, cb, rd, cd);
    cout << ans << '\n';
  }
  cout << endl;
  return 0;
}
