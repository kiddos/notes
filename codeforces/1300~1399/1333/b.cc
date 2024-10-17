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
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  bool can_be_larger = false, can_be_smaller = false;
  for (int i = 0; i < n; ++i) {
    if (b[i] > a[i]) {
      if (!can_be_larger) {
        cout << "NO" << endl;
        return;
      }
    }
    if (b[i] < a[i]) {
      if (!can_be_smaller) {
        cout << "NO" << endl;
        return;
      }
    }

    if (a[i] == 1) {
      can_be_larger = true;
    }
    if (a[i] == -1) {
      can_be_smaller = true;
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
