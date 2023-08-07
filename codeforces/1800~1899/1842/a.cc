#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];

  ll sum1 = accumulate(a.begin(), a.end(), 0LL);
  ll sum2 = accumulate(b.begin(), b.end(), 0LL);
  if (sum1 > sum2) {
    cout << "Tsondu" << endl;
  } else if (sum1 < sum2) {
    cout << "Tenzing" << endl;
  } else {
    cout << "Draw" << endl;
  }
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
