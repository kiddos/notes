#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<string> t(n);
  for (int i = 0; i < n; ++i) cin >> t[i];

  int same = 1;
  for (int i = 1; i < n; ++i) {
    same += t[i] == t[0];
  }
  cout << same << endl;
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
