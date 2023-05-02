#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());
  int need = 1;
  int i = 0;
  ll ans = 0;
  while (i < n) {
    if (a[i] > need) {
      ans += a[i] - need;
      i++;
    }
    while (i < n && a[i] <= need) i++;
    need++;
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
