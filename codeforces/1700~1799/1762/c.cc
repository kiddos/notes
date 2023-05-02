#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr int MOD = 998244353;
constexpr int SIZE = 200000;
vector<ll> pow2(SIZE+1, 1);

void precompute() {
  for (int i = 1; i <= SIZE; ++i) {
    pow2[i] = pow2[i-1] * 2;
    pow2[i] %= MOD;
  }
}

void solve() {
  int n = 0;
  cin >> n;
  string s;
  cin >> s;

  ll ans = 0;
  int one_len = 0, zero_len = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      one_len++;
      zero_len = 0;
    } else {
      zero_len++;
      one_len = 0;
    }

    ans += pow2[max(one_len, zero_len)-1];
    ans %= MOD;
  }
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
