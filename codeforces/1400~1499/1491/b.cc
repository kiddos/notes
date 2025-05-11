#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, u = 0, v = 0;
  cin >> n >> u >> v;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int diff = 0;
  for (int i = 1; i < n; ++i) {
    diff = max(diff, abs(a[i] - a[i-1]));
  }

  if (diff > 1) {
    cout << "0" << endl;
  } else if (diff == 1) {
    cout << min(u, v) << endl;
  } else {
    cout << min(u + v, v + v) << endl;
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
