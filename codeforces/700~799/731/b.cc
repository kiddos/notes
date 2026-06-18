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
  for (int i = 0; i < n; ++i) {
    if (i == n-1) {
      if (a[i] < 0) {
        cout << "NO" << endl;
        return;
      }

      if (a[i] % 2 == 1) {
        cout << "NO" << endl;
        return;
      }
    } else {
      if (a[i] < 0) {
        cout << "NO" << endl;
        return;
      }

      if (a[i] % 2 == 1) {
        a[i+1]--;
      }
    }
  }
  cout << "YES" << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  solve();
  return 0;
}
