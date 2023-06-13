#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  ll n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  ll x = 0;
  vector<int> xors(2*n+1);
  xors[0] = 1;

  ll not_ans = 0;
  for (int i= 0; i < n; ++i) {
    x ^= a[i];
    for (ll d = 0; d*d <= 2 * n; ++d) {
      ll y = d*d ^ x;
      if (y <= 2 * n)
      not_ans += xors[y];
      // cout << "squares: " << y  << " ^ " << x << endl;
    }
    xors[x]++;
  }

  // cout << "not ans: " << not_ans << endl;
  ll ans = n * (n+1) / 2 - not_ans;
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
