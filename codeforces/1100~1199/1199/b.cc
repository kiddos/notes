#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  i64 H = 0, L = 0;
  cin >> H >> L;
  // (A + H)^ 2 = A^ 2 + L^2
  // => A^2 + 2AH + H^2 = A^2 + L^2
  // => 2AH = L^2 - H^2
  // => A = (L^2 - H^2) / 2H

  double A = (L * L - H * H) / 2.0 / H;
  cout << setprecision(12) << A << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
