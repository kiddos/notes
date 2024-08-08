#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> b(n-1);
  for (int i = 0; i < n - 1; ++i) {
    cin >> b[i];
  }

  vector<int> a(n);
  for (int i = 1; i < n-1; ++i) {
    a[i] = b[i] | b[i-1];
  }
  a[0] = b[0];
  a.back() = b.back();

  for (int i = 0; i < n-1; ++i) {
    if ((a[i] & a[i+1]) != b[i]) {
      cout << "-1" << endl;
      return;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
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
