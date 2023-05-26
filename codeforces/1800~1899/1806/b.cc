#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int zeros = 0;
  int not_one = 0;
  for (int val : a) {
    zeros += (val == 0);
    not_one += (val > 1);
  }
  if (zeros == n) {
    cout << "1" << endl;
    return;
  }
  if (n - zeros >= n / 2) {
    cout << "0" << endl;
    return;
  }
  if (not_one > 0) {
    cout << "1" << endl;
    return;
  }

  cout << "2" << endl;
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
