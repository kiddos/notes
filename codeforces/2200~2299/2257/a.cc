#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0;
  cin >> n >> m;
  vector<string> w(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
  }
  vector<string> a(m);
  for (int i = 0; i < m; ++i) {
    cin >> a[i];
  }
  vector<bool> found(26);
  for (int i = 0; i < n; ++i) {
    int c = w[i][0] - 'a';
    found[c] = true;
  }

  for (int i = 0; i < m; ++i) {
    for (char ch : a[i]) {
      int c = ch - 'A';
      if (!found[c]) {
        cout << "NO" << endl;
        return;
      }
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
