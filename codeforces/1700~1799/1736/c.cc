#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  ll ans = 0;
  for (int i = 1, j = 1; i <= n; ++i) {
    int idx = i - j + 1;
    while (a[i] < idx) {
      j++;
      idx = i - j + 1;
    }
    ans += i - j + 1;
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
