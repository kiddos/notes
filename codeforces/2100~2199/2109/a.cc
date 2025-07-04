#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i < n; ++i) {
    if (a[i] == 0 && a[i-1] == 0) {
      cout << "YES" << endl;
      return;
    }
  }
  int total = accumulate(a.begin(), a.end(), 0);
  if (total == n) {
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
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
