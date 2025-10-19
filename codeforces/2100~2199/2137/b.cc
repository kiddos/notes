#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
  }

  vector<int> q(n);
  for (int i = 0; i < n; ++i) {
    q[i] = n - p[i] + 1;
  }
  for (int i = 0; i < n; ++i) {
    cout << q[i] << " ";
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
