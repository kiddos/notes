#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, c = 0;
  cin >> n >> c;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> orbits(101);
  for (int i = 0; i < n; ++i) orbits[a[i]]++;

  int ans = 0;
  for (int o = 1; o <= 100; ++o) {
    ans += min(orbits[o], c);
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
