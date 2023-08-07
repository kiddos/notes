#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n+1);
  for (int i = 1; i <= n; ++i) cin >> p[i];

  int not_happy = 0;
  for (int i = 1; i <= n; ++i) {
    not_happy += p[i] == i;
  }

  int ans = (not_happy + 1) / 2;
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
