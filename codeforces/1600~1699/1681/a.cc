#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  int m = 0;
  cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) cin >> b[i];

  int alice = *max_element(a.begin(), a.end());
  int bob = *max_element(b.begin(), b.end());

  if (alice >= bob) {
    cout << "Alice" << endl;
  } else {
    cout << "Bob" << endl;
  }

  if (bob >= alice) {
    cout << "Bob" << endl;
  } else {
    cout << "Alice" << endl;
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
