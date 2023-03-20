#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n = 0;
  cin >> n;

  ll l = 1, r = n;
  ll turn = 1;
  while (l <= r) {
    ll m = l + (r-l) / 2;
    ll total = (m + 1) * m / 2;
    if (total <= n) {
      turn = m;
      l = m+1;
    } else {
      r = m-1;
    }
  }

  // cout << "turn=" << turn << endl;

  int which = 1;
  int alice = 0, bob = 0;
  for (int i = 1; i <= turn; ++i) {
    if (which == 0 || which == 1) {
      alice += i;
    } else if (which == 2 || which == 3) {
      bob += i;
    }
    which = (which + 1) % 4;
    n -= i;
  }
  if (which < 2) {
    alice += n;
  } else {
    bob += n;
  }
  cout << alice << " " << bob << endl;
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
