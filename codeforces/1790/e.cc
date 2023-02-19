#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve(ll x) {
  if (x % 2 == 1) {
    cout << "-1" << endl;
    return;
  }

  for (int i = 28; i >= 0; --i) {
    if ((x & (1LL<<i)) && (x & (1LL<<(i+1)))) {
      cout << "-1" << endl;
      return;
    }
  }

  ll a = 0, b = 0;
  for (int i = 29; i > 0; --i) {
    if (x & (1LL<<i)) {
      a ^= (1LL<<i);
      a ^= (1LL<<(i-1));
      b ^= (1LL<<(i-1));
    }
  }
  cout << a << " " << b << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    ll x = 0;
    cin >> x;
    solve(x);
  }
  return 0;
}
