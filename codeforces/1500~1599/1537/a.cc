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
  i64 diff = 0;
  for (int i = 0; i < n; ++i) {
    diff += a[i] - 1;
  }
  if (diff == 0) {
    cout << "0" << endl;
  } else if (diff < 0) {
    cout << "1" << endl;
  } else {
    cout << diff << endl;
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
