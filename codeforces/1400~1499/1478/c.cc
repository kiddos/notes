#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  int m = 2 * n;
  vector<i64> d(m);
  for (int i = 0; i < m; ++i) {
    cin >> d[i];
  }
  map<i64,int> count;
  for (int i = 0; i < m; ++i) {
    count[d[i]]++;
  }
  for (auto [x, c] : count) {
    if (c != 2 || x % 2 != 0) {
      cout << "NO" << endl;
      return;
    }
  }

  vector<i64> values;
  for (auto it = count.begin(); it != count.end(); ++it) {
    values.push_back(it->first);
  }
  vector<i64> a(n);
  i64 prefix = 0;
  for (int i = n-1; i >= 0; --i) {
    i64 divisor = (i+1) * 2;
    i64 left = values[i] - prefix * 2;
    if (left % divisor != 0 || left <= 0) {
      cout << "NO" << endl;
      return;
    }
    a[i] = left / divisor;
    prefix += a[i];
  }
  for (int i = 1; i < n; ++i) {
    if (a[i-1] > a[i]) {
      cout << "NO" << endl;
      return;
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
