#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      cout << "0" << endl;
      return;
    }
  }

  int neg = 0;
  for (int i = 0; i < n; ++i) {
    neg += a[i] < 0;
  }

  if (neg % 2 == 0) {
    cout << "1" << endl;
    cout << "1 0" << endl;
  } else {
    cout << "0" << endl;
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
