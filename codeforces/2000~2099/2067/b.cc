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
  sort(a.begin(), a.end());
  vector<int> b, c;
  for (int i = 0; i < n; i += 2) {
    b.push_back(a[i]);
    c.push_back(a[i+1]);
  }
  int m = b.size();
  for (int i = 0; i+1 < m; ++i) {
    if (b[i+1] <= b[i]+1) {
      b[i+1] = b[i]+1;
    }
    if (c[i+1] <= c[i]+1) {
      c[i+1] = c[i]+1;
    }
  }

  if (b == c) {
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
