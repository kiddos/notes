#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0, m = 0, q = 0;
  cin >> n >> m >> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    cin>> b[i];
  }

  vector<bool> seen(n+1);
  for (int i = 0, j = 0; i < m; ++i) {
    if (!seen[b[i]]) {
      if (a[j] == b[i]) {
        j++;
      } else {
        cout << "TIDAK" << endl;
        return;
      }
      seen[b[i]] = true;
    }
  }

  cout << "YA" << endl;
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
