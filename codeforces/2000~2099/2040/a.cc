#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, k =0;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n; ++i) {
    bool valid = true;
    for (int j = 0; j < n; ++j) {
      if (i != j && abs(a[i] - a[j]) % k == 0) {
        valid = false;
        break;
      }
    }
    if (valid) {
      cout << "YES" << endl;
      cout << i+1 << endl;
      return;
    }
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
