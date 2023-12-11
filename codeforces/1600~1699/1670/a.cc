#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  int neg = 0;
  for (int i = 0; i < n; ++i) neg += a[i] < 0;
  
  for (int i = 0; i < n; ++i) {
    if (i < neg) a[i] = -abs(a[i]);
    else a[i] = abs(a[i]);
  }

  for (int i = 1; i < n; ++i) {
    if (a[i-1] > a[i]) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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