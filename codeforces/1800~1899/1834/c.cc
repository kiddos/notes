#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  string S, T;
  cin >> S >> T;

  if (S == T) {
    cout << "0" << endl;
    return;
  }

  int normal = 0;
  for (int i = 0; i < n; ++i) {
    normal += S[i] != T[i];
  }

  int reversed = 0;
  for (int i = 0; i < n; ++i) {
    reversed += S[i] != T[n-i-1];
  }

  int x = max(normal-1, 0) * 2 + 1;
  int y = max(reversed-1, 0) * 2 + 1;
  if ((x / 2) % 2 == 1) {
    x++;
  }
  if ((y / 2) % 2 == 0) {
    y++;
  }

  int ans = min(x, y);
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
