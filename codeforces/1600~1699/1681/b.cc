#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int m = 0;
  cin >> m;
  int top = 0;
  for (int i = 0; i < m; ++i) {
    int b = 0;
    cin >> b;
    top += b;
    top %= n;
  }

  cout << a[top] << endl;
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
