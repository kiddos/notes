#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  vector<int> f(n);
  for (int i = 0; i < n; ++i) cin >> f[i];

  cout << f[0]-s[0] << " ";
  for (int i = 1; i < n; ++i) {
    cout << f[i] - max(s[i], f[i-1]) << " ";
  }
  cout << endl;
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
