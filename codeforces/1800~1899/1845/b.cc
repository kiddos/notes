#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  ll Xa = 0, Ya = 0, Xb = 0, Yb = 0, Xc = 0, Yc = 0;
  cin >> Xa >> Ya >> Xb >> Yb >> Xc >> Yc;

  ll ans = 1;
  if (Xa <= Xb && Xa <= Xc) {
    ans += min(Xb, Xc) - Xa;
  }
  if (Xa >= Xb && Xa >= Xc) {
    ans += Xa - max(Xb, Xc);
  }

  if (Ya <= Yb && Ya <= Yc) {
    ans += min(Yb, Yc) - Ya;
  }
  if (Ya >= Yb && Ya >= Yc) {
    ans += Ya - max(Yc, Yb);
  }

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
