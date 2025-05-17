#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  vector<int> p(m, n);
  for (int i = 0, j = 0; i < n; ++i) {
    if (a[i] >= b[j]) {
      p[j++] = i;
    }
    if (j == m) break;
  }

  if (p.back() < n) {
    cout << "0" << endl;
    return;
  }

  vector<int> s(m, -1);
  for (int i = n-1, j = m-1; i >= 0; --i) {
    if (a[i] >= b[j]) {
      s[j--] = i;
    }
    if (j < 0) break;
  }

  // for (int i = 0; i < m; ++i) {
  //   cout << p[i] << " ";
  // }
  // cout << endl;
  // for (int i = 0; i < m; ++i) {
  //   cout << s[i] << " ";
  // }
  // cout << endl;

  int ans = numeric_limits<int>::max();
  for (int i = 0; i < m; ++i) {
    int prev = i > 0 ? p[i-1] : -1;
    int next = i+1 < m ? s[i+1] : n;
    if (prev < next) {
      ans = min(ans, b[i]);
    }
  }
  if (ans == numeric_limits<int>::max()) {
    cout << "-1" << endl;
  } else {
    cout << ans << endl;
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
