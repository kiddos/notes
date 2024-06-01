#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  sort(a.begin(), a.end());
  int j = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] % a[0] != 0) {
      j = i;
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] % a[0] != 0 && a[i] % a[j] != 0) {
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
