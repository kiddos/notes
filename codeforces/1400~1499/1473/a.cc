#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, d = 0;
  cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  bool found = false;
  for (int i = 0; i < n; ++i) {
    if (a[i] > d) {
      found = true;
      break;
    }
  }
  if (!found) {
    cout << "YES" << endl;
    return;
  }

  found = false;
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (a[i] + a[j] <= d) {
        found = true;
        break;
      }
    }
  }

  if (found) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
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
