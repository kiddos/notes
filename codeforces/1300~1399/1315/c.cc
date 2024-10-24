#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
  int n = 0;
  cin >> n;
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  set<int> pool;
  for (int i = 1; i <= 2 * n; ++i) {
    pool.insert(i);
  }

  vector<int> a(n * 2);
  for (int i = 0; i < n; ++i) {
    a[i*2] = b[i];
    pool.erase(b[i]);
  }
  for (int i = 0; i < 2 * n; i += 2) {
    auto it = pool.lower_bound(a[i] + 1);
    if (it == pool.end()) {
      cout << "-1" << endl;
      return;
    }
    a[i+1] = *it;
    pool.erase(it);
  }

  for (int i = 0 ; i < 2 * n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;
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
