#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<int> p(n+1);
  iota(p.begin(), p.end(), 0);
  if (a == p) {
    cout << "0" << endl;
  } else if (a[1] == 1 || a[n] == n) {
    cout << "1" << endl;
  } else if (a[1] == n && a[n] == 1) {
    cout << "3" << endl;
  } else {
    cout << "2" << endl;
  }
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
