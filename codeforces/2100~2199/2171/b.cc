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
  if (a[0] == -1 && a.back() == -1) {
    a[0] = a.back() = 0;
  } else if (a[0] == -1) {
    a[0] = a.back();
  } else if (a.back() == -1) {
    a.back() = a[0];
  }
  for (int i = 1; i < n-1; ++i) {
    if (a[i] == -1) {
      a[i] = 0;
    }
  }
  cout << abs(a[0] - a.back()) << endl;
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
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
