#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n+1);
  for (int i = 1; i <= n; ++i) cin >> a[i];

  if (a[1] != n) {
    cout << "NO" << endl;
    return;
  }

  vector<int> b;
  for (int i = n; i >= 1; --i) {
    while ((int)b.size() < a[i]) {
      b.push_back(i);
    }
  }
  b.insert(b.begin(), 0);

  for (int i = 1; i <= n; ++i) {
    if (b[i] != a[i]) {
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
