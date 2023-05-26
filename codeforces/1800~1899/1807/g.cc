#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> c(n);
  for (int i = 0; i < n; ++i) cin >> c[i];

  sort(c.begin(), c.end());
  if (c[0] != 1) {
    cout << "NO" << endl;
    return;
  }

  ll p = 1;
  for (int i = 1; i < n; ++i) {
    if (c[i] > p) {
      cout << "NO" << endl;
      return;
    }
    p += c[i];
  }
  cout << "YES" << endl;
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
