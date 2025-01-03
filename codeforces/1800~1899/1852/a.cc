#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k = 0;
  cin >> n >> k;
  vector<i64> a(n+1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  if (a[1] != 1) {
    cout << "1" << endl;
    return;
  }

  int i = 1;
  i64 x = 1;
  while (k-- > 0) {
    while (i+1 <= n && a[i+1] <= x + i) {
      i++;
    }
    x += i;
  }
  cout << x << endl;
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
