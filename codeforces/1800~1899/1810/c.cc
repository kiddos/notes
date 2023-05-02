#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  ll c = 0, d = 0;
  cin >> n >> c >> d;

  vector<ll> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());

  ll ans = n * c + d;
  ll last = 0;
  ll missing = 0;
  ll remove = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == last) {
      remove++;
    } else {
      missing += a[i] - last - 1;
      last = a[i];
    }
    ans = min(ans, missing * d + (n-i-1) * c + remove * c);
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
