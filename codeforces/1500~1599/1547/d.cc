#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  vector<int> y(n);
  int z = x[0];
  for (int i = 0; i < n; ++i) {
    y[i] = (z ^ x[i]) & z;
    z |= x[i];
  }
  for (int i = 0; i < n; ++i) {
    cout << y[i] << " ";
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
