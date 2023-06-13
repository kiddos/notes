#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll N = 0, D = 0;
  cin >> N >> D;
  vector<ll> P(N);
  for (int i = 0; i < N; ++i) cin >> P[i];

  sort(P.begin(), P.end());
  int l = 0, r = N-1;
  int ans = 0;
  while (l <= r) {
    ll power = P[r];
    while (l < r && power <= D) {
      power += P[r];
      l++;
    }
    if (power > D) {
      ans++;
    }
    r--;
  }

  cout << ans << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
