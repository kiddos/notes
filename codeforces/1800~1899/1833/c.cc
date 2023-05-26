#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> even, odd;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 == 0) {
      even.push_back(a[i]);
    } else {
      odd.push_back(a[i]);
    }
  }
  sort(even.begin(), even.end());
  sort(odd.begin(), odd.end());

  bool e = true, o = true;
  for (int i = 0; i < n; ++i) {
    if (a[i] % 2 != 0) {
      // try to build even array
      auto p = upper_bound(odd.begin(), odd.end(), a[i]-1);
      if (p == odd.begin()) {
        e = false;
      }
    } else {
      // try to build odd array
      auto p = upper_bound(odd.begin(), odd.end(), a[i]-1);
      if (p == odd.begin()) {
        o = false;
      }
    }
  }

  if (e || o) {
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
