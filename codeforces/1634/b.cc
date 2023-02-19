#include <bits/stdc++.h>

using namespace std;

typedef long long LONG;

bool solve(vector<LONG>& a, LONG x, LONG y) {
  int n = a.size();
  bool p = y % 2 == 0;
  for (int i = n-1; i >= 0; --i) {
    if (a[i] % 2 == 1) p = !p;
  }
  return p == (x % 2 == 0);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T = 0;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n = 0;
    LONG x = 0, y = 0;
    cin >> n >> x >> y;
    vector<LONG> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    bool ans = solve(a, x, y);
    if (ans) cout << "Alice\n";
    else cout << "Bob\n";
  }
  cout << flush;
  return 0;
}
