#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  int total = n * m;
  vector<ll> b(total);
  for (int i = 0; i < total; ++i) {
    cin >> b[i];
  }

  sort(b.begin(), b.end());
  ll first = b[0], second = b[1];
  if (n > m) {
    swap(first, second);
  }

  ll ans1 = (b.back() - first) * (m-1) +
    (b.back() - second) * (n-1) +
    (n-1) * (m-1) * (b.back() - b[0]);

  first = b.back();
  second = b[total-2];
  if (n > m) {
    swap(first, second);
  }

  ll ans2 = (first - b[0]) * (m-1) +
    (second - b[0]) * (n-1) +
    (n-1) * (m-1) * (b.back() - b[0]);

  ll ans = max(ans1, ans2);
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
