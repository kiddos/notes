#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;

  int x = n;
  int p2 = 0;
  while (x > 0) {
    p2++;
    x >>= 1;
  }

  if (k <= 30 && n >= (1<<k)) {
    cout << (1<< k) << endl;
    return;
  }

  p2 = min(p2, k);

  ll ans = 1;
  for (int i = p2; i >= 0; --i) {
    if (n & (1<< i)) {
      ans += (1<<i);
    }
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
