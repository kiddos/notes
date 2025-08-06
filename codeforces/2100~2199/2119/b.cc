#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int px = 0, py = 0, qx = 0, qy = 0;
  cin >> px >> py >> qx >> qy;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  i64 dx = qx - px;
  i64 dy = qy - py;
  double require = sqrt(dx * dx + dy * dy);

  i64 total = accumulate(a.begin(), a.end(), 0LL);
  double all = total + require;
  double max_len = max(require, (double)*max_element(a.begin(), a.end()));

  if (max_len <= all - max_len) {
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
