#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

void solve(ll n, ll x) {
  ll ans = n;
  bool bit_set = false;
  for (int i = 63; i >= 0; --i) {
    ll a = (n & (1ULL<<i)), b = (x & (1ULL<<i));
    if (b != a) {
      if (!bit_set) {
        if (!b) {
          ans |= (1ULL<<(i+1));
          for (int j = i; j >= 0; --j) ans &= ~(1ULL << j);
        } else {
          ans ^= (1ULL<<i);
          for (int j = i-1; j >= 0; --j) ans &= ~(1ULL << j);
        }
        bit_set = true;
      }
    }

    if (b && bit_set) {
      cout << "-1" << endl;
      return;
    }
  }

  if (ans >= n) {
    cout << ans << endl;
  } else {
    cout << "-1" << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    ll n = 0, x = 0;
    cin >> n >> x;

    solve(n, x);
  }
  return 0;
}
