#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];

  auto check = [&]() -> bool {
    for (int i = 0; i < n; ++i) {
      if (a[i] > a.back() || b[i] > b.back()) {
        swap(a[i], b[i]);
        if (a[i] > a.back() || b[i] > b.back()) {
          return false;
          break;
        }
      }
    }
    return true;
  };


  if (check()) {
    cout << "YES" << endl;
    return;
  }

  swap(a.back(), b.back());

  if (check()) {
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
