#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

void solve() {
  ll n = 0;
  cin >> n;
  if (n == 4) {
    cout << "26" << endl;
    return;
  }

  ll ans = 26LL + ((n - 5) * 2 + 11 + 11) * (n - 4) / 2;
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
