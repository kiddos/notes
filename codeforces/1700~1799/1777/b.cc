#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MAX_VAL = 100000;
constexpr int MOD = 1e9 + 7;

ll f[MAX_VAL+1];

void precompute() {
  f[0] = f[1] = 1;
  for (int i = 2; i <= MAX_VAL; ++i) {
    f[i] = f[i-1] * i;
    f[i] %= MOD;
  }
}

void solve() {
  ll n = 0;
  cin >> n;

  ll ans = n * (n-1);
  ans %= MOD;
  ans *= f[n];
  ans %= MOD;
  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  precompute();

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    solve();
  }
  return 0;
}
