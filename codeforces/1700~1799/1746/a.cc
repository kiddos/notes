#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  bool has_one = false;
  for (int i = 0; i < n ; ++i) {
    int a = 0;
    cin >> a;
    if (a == 1) has_one = true;
  }
  if (has_one) cout << "YES" << endl;
  else cout << "NO" << endl;
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
